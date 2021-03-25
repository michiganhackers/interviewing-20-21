class SnakeGame {
    
private:
    
    unordered_map<int, unordered_set<int>> activeSnakeSpots;
    deque<pair<int, int>> snake;
    vector<vector<int>> food;
    int width;
    int height;
    int gameScore;
    
public:
    
    SnakeGame(int width, int height, vector<vector<int>>& food) : food(food), width(width), 
                                                                  height(height), gameScore(0) {
        snake.push_front(make_pair(0, 0));
        activeSnakeSpots[0].insert(0);
    }
    
    int move(string direction) {
        
        // Retrieving the new postion of the snake's head based on the direction
        
        pair<int, int> newHeadPosition = getNewHeadPosition(direction);

        // Checking if the new head position of the snake is out of bounds
        
        if(spotIsOutOfBounds(newHeadPosition.first, newHeadPosition.second)) 
            return -1;
        
        // Checking if the new head position has food
        // If yes, adding the new head position to the snake and updating the game score
        
        if(gameScore < static_cast<int>(food.size())
           && spotHasFood(newHeadPosition.first, newHeadPosition.second)) {
            snake.push_front(newHeadPosition);
            activeSnakeSpots[newHeadPosition.first].insert(newHeadPosition.second);
            return ++gameScore;
        }
        
        // Removing the previous position of the snake's tail
        
        activeSnakeSpots[snake.back().first].erase(snake.back().second);
        snake.pop_back();
        
        
        // Checking if the new head position is already occupied
        
        if(spotIsOccupied(newHeadPosition.first, newHeadPosition.second)) 
            return -1;
        
        // Adding the new head position to the snake
        
        snake.push_front(newHeadPosition);
        activeSnakeSpots[newHeadPosition.first].insert(newHeadPosition.second);
        
        return gameScore;
    }
    
private:
    
    pair<int, int> getNewHeadPosition(const string& direction) {
        
        if(direction == "U")
            return make_pair(snake.front().first - 1, snake.front().second);
        else if(direction == "D")
            return make_pair(snake.front().first + 1, snake.front().second);
        else if(direction == "L")
            return make_pair(snake.front().first, snake.front().second - 1);
        else
            return make_pair(snake.front().first, snake.front().second + 1);
        
    }
    
    bool spotIsOutOfBounds(int row, int col) {
        return row < 0 || row >= height || col < 0 || col >= width;
    }
    
    bool spotHasFood(int row, int col) {
        return food[gameScore][0] == row && food[gameScore][1] == col;
    }
    
    bool spotIsOccupied(int row, int col) {
        return activeSnakeSpots.find(row) != activeSnakeSpots.end()
            && activeSnakeSpots[row].find(col) != activeSnakeSpots[row].end();
    }
    
};