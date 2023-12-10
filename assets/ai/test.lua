
function Interact(table,isWhite)
    print("Interact")
    for k,v in pairs(table) do
        print(k)
        for k2,v2 in pairs(v) do
            print(k2,v2)
        end
    end
    print(isWhite)
end