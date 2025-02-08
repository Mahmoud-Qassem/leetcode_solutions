class NumberContainers {
public:
    map<int,int>carries;
    map<int,set<int>>idexs;

    NumberContainers() {
        idexs.clear();
        carries.clear();
    }
    
    void change(int index, int number) {
        if(carries[index]){
            idexs[ carries[index] ].erase(idexs[ carries[index] ].find(index));
        }
        carries[index]=number;
        idexs[number].insert(index);
    }
    
    int find(int number) {
        if(not idexs[number].size())return -1;

        auto least=idexs[number].begin();
        return *least;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */