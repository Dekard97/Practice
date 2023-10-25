bool is_can_exit_from_maze(std::vector<std::string>& arr, int row, int col,std::string move="") {
    
    if (arr[row][col]=='E'){
        return true;
    }
    else{
        if(arr[row][col]=='#'){
            return false;
        }
        else{
            if (move == "up"){
                return is_can_exit_from_maze(arr,row+1,col,"up")
                    || is_can_exit_from_maze(arr,row,col-1,"left")
                        || is_can_exit_from_maze(arr,row,col+1,"right");
            }else if(move=="down"){
                return is_can_exit_from_maze(arr,row-1,col,"down")
                    || is_can_exit_from_maze(arr,row,col-1,"left")
                        || is_can_exit_from_maze(arr,row,col+1,"right");
            }else if(move=="left"){
                return is_can_exit_from_maze(arr,row+1,col,"up")
                    || is_can_exit_from_maze(arr,row,col-1,"left")
                        || is_can_exit_from_maze(arr,row-1,col,"down");
            }else if(move=="right"){
                return is_can_exit_from_maze(arr,row+1,col,"up")
                    || is_can_exit_from_maze(arr,row,col+1,"right")
                        || is_can_exit_from_maze(arr,row-1,col,"down");
            }else{
                return is_can_exit_from_maze(arr,row+1,col,"up")
                    || is_can_exit_from_maze(arr,row-1,col,"down")
                        || is_can_exit_from_maze(arr,row,col-1,"left")
                            || is_can_exit_from_maze(arr,row,col+1,"right");
            }
        }
    }
    
}