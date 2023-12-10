#include "controllerLua.hpp"

ControllerLua::ControllerLua(bool isWhite, std::string scriptPath) : Controller(isWhite,ControllerType::AI), scriptPath(scriptPath) {
    L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, scriptPath.c_str());
}


pair<int,int> ControllerLua::Interact(vector<vector<pieces::Piece*>> board,list<pieces::Move> movesPos) {
    
    
    // execute the script
    lua_getglobal(L, "Interact");
    // add table to arguments
    lua_newtable(L);
    for (int i = 0; i < board.size(); i++)
    {
        lua_pushnumber(L, i+1);
        lua_newtable(L);
        for (int j = 0; j < board[i].size(); j++)
        {
            lua_pushnumber(L, j+1);
            if (board[i][j] == nullptr) {
                lua_pushstring(L, "null");
            } else{
                // make a table with the piece
                lua_newtable(L);
                // add the type
                lua_pushstring(L, "name");
                lua_pushstring(L, board[i][j]->getName().c_str());
                lua_settable(L, -3);
                // add the color
                lua_pushstring(L, "color");
                lua_pushboolean(L, (int)board[i][j]->getColor());
                lua_settable(L, -3);    
            }
            lua_settable(L, -3);
        }
        lua_settable(L, -3);
    }


    // add isWhite to arguments
    lua_pushboolean(L, (int)getIsWhite());

    

    
    if (movesPos.size() > 0) {
        lua_newtable(L);
        int i = 1;
        for (auto move : movesPos)
        {
            lua_pushnumber(L, i);
            lua_newtable(L);
            lua_pushstring(L, "x");
            lua_pushnumber(L, move.x);
            lua_settable(L, -3);
            lua_pushstring(L, "y");
            lua_pushnumber(L, move.y);
            lua_settable(L, -3);
            lua_settable(L, -3);
            i++;
        }
    } else {
        lua_pushstring(L, "ntm");
    }

    // execute the function
    lua_call(L, 3, 2);


    // get the return value
    if (lua_isnumber(L, -2)) {
        int x = lua_tonumber(L, -2);
        int y = lua_tonumber(L, -1);
        lua_pop(L, 2);
        return make_pair(x,y);
    }

    // check if there is an error
    if (lua_isstring(L, -1)) {
        std::cout << "Error: " << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1);
        return make_pair(-1,-1);
    }

    return make_pair(-1,-1);
}