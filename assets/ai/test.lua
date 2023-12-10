
test = true

function Interact(table,isWhite,movesPos)
    print("Interact")
    -- for k,v in pairs(table) do
    --     print(k)
    --     for k2,v2 in pairs(v) do
    --         if v2 == "null" then
    --             print(k2,v2)
    --         else
    --             for k3,v3 in pairs(v2) do
    --                 print(k3,v3)
    --             end
    --         end
    --     end
    -- end
    -- print(isWhite)
    if movesPos ~= "ntm" then
        print("movesPos")
        for k,v in pairs(movesPos) do
            print(k,v)
        end
    else 
        print("movesPos is nil")
    end
    return 0,1
end