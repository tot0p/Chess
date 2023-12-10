#pragma once

#include "controller.hpp"

#include <string>
#include "lua.hpp"


class ControllerLua : public Controller {
    public: 
        ControllerLua(bool isWhite, std::string scriptPath);
        pair<int,int> Interact(vector<vector<pieces::Piece*>> board,list<pieces::Move> movesPos);

        void reset() {
            lua_State* L = luaL_newstate();
        };

    private:
        lua_State* L;
        std::string scriptPath;
};