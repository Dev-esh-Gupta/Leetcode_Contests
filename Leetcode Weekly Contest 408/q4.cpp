
class Solution {
public:
    bool canReachCorner(int targetX, int targetY, vector<vector<int>>& obstaclesList) {
        if (isBlocked(0, 0, obstaclesList) || isBlocked(targetX, targetY, obstaclesList)) {
            return false;
        }

        vector<pair<int, int>> movementDirections = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> positionQueue;
        vector<vector<bool>> visitedPositions = initializeVisitedPositions(targetX, targetY);

        addPositionToQueue(0, 0, positionQueue, visitedPositions);

        while (!positionQueue.empty()) {
            auto [currentX, currentY] = positionQueue.front();
            positionQueue.pop();

            if (currentX == targetX && currentY == targetY) {
                return true;
            }

            processPosition(currentX, currentY, targetX, targetY, movementDirections, obstaclesList, positionQueue, visitedPositions);
        }

        return false;
    }

private:
    bool isBlocked(int currentX, int currentY, const vector<vector<int>>& obstaclesList) {
        for (const auto& obstacle : obstaclesList) {
            int deltaX = currentX - obstacle[0];
            int deltaY = currentY - obstacle[1];
            int distanceSquaredToCenter = deltaX * deltaX + deltaY * deltaY;
            int circleRadiusSquared = obstacle[2] * obstacle[2];
            if (distanceSquaredToCenter <= circleRadiusSquared) {
                return true;
            }
        }
        return false;
    }

    vector<vector<bool>> initializeVisitedPositions(int maxX, int maxY) {
        return vector<vector<bool>>(maxX + 1, vector<bool>(maxY + 1, false));
    }

    void addPositionToQueue(int x, int y, queue<pair<int, int>>& positionQueue, vector<vector<bool>>& visitedPositions) {
        positionQueue.push({x, y});
        visitedPositions[x][y] = true;
    }

    void processPosition(int currentX, int currentY, int targetX, int targetY, 
                         const vector<pair<int, int>>& movementDirections, 
                         const vector<vector<int>>& obstaclesList, 
                         queue<pair<int, int>>& positionQueue, 
                         vector<vector<bool>>& visitedPositions) {
        for (auto [deltaX, deltaY] : movementDirections) {
            int nextX = currentX + deltaX;
            int nextY = currentY + deltaY;

            if (nextX >= 0 && nextY >= 0 && nextX <= targetX && nextY <= targetY &&
                !visitedPositions[nextX][nextY] && !isBlocked(nextX, nextY, obstaclesList)) {
                addPositionToQueue(nextX, nextY, positionQueue, visitedPositions);
            }
        }
    }
};