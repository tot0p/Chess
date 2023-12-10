
movesTest = {}
movesTestIndex = 0

function NotContains(val) 
    for k,v in pairs(movesTest) do
        if v[2] == val[2] and v[1] == val[1] then
            return false
        end
    end
    return true
end

function Interact(board,isWhite,movesPos)
    if movesPos == nil then
        for k,v in pairs(board) do
            for k2,v2 in pairs(v) do
                if v2 ~= "null" and NotContains({k,k2}) then
                    print("test", k-1," " , k2-1)
                    movesTest[movesTestIndex] = {k,k2}
                    movesTestIndex = movesTestIndex + 1
                    return k-1,k2-1
                end
            end
        end
    else
        print("moves")
        movesTest = {}
        movesTestIndex = 0
        for k,v in pairs(movesPos) do
            return v["x"] , v["y"]
        end       
    end
    return -1,-1
end