#include "controllerLua.hpp"

ControllerLua::ControllerLua(bool isWhite, std::string scriptPath) : Controller(isWhite,ControllerType::AI), scriptPath(scriptPath) {
    L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, scriptPath.c_str());
}


pair<int,int> ControllerLua::Interact(vector<vector<pieces::Piece*>> board) {
    
    // lua_getglobal(L, "Interact");
    // lua_newtable(L);
    // for (int i = 0; i < board.size(); i++)
    // {
    //     lua_pushnumber(L, i+1);
    //     lua_newtable(L);
    //     for (int j = 0; j < board[i].size(); j++)
    //     {
    //         lua_pushnumber(L, j+1);
    //         lua_pushnumber(L, (int)board[i][j]->getType());
    //         lua_settable(L, -3);
    //     }
    //     lua_settable(L, -3);
    // }
    // lua_pushnumber(L, (int)getIsWhite());
    // lua_call(L, 2, 2);
    // int x = lua_tonumber(L, -2);
    // int y = lua_tonumber(L, -1);
    // lua_pop(L, 2);

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
                lua_pushnumber(L, -1);
            } else{
                lua_pushnumber(L, (int)board[i][j]->getLetter());                
            }
            lua_settable(L, -3);
        }
        lua_settable(L, -3);
    }


    // add isWhite to arguments
    lua_pushboolean(L, (int)getIsWhite());
    // call the function
    lua_call(L, 2, 2);

    // check if there is an error
    if (lua_isstring(L, -1)) {
        std::cout << "Error: " << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1);
        return make_pair(-1,-1);
    }

    return make_pair(-1,-1);
}