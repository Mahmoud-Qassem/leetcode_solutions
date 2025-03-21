class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        unordered_map<string,bool>sup;
        for(auto&su:supplies)sup[su]=true;
        
        vector<string>cook;
        for(int i=0;i<n;++i){
            if(sup[recipes[i]])continue;
            bool newRecipeAdded=1;
            for(auto&ing:ingredients[i]){
                if(!sup[ ing ]){
                    newRecipeAdded=0;
                    break;
                }
            }
            if(newRecipeAdded){
                sup[recipes[i]]=true;
                cook.push_back(recipes[i]);
                i=-1;
            }
        }
        return cook;
    }
};


