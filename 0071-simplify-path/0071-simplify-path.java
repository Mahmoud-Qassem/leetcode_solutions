class Solution {
    public String simplifyPath(String path) {
        int n = path.length();
        List<String> stk = new LinkedList<>();
        for(int i =0 ;i< n;++i) {
            if (path.charAt(i) == '/') {
                continue;
            }
            int dots = 0;
            String crnt = "";
            if (path.charAt(i) == '.'){
                while (i < n && path.charAt(i) == '.') {
                    crnt += path.charAt(i);
                    ++i;
                    ++dots;
                }
                if(dots ==1 && (i == n || path.charAt(i)=='/')){
                    continue;
                }
                else if(dots ==1 ){
                    while (i < n && path.charAt(i) != '/') {
                        crnt += path.charAt(i);
                        ++i;
                    }
                    stk.add(crnt);
                }

                else if(dots == 2 && (i == n || path.charAt(i)=='/')){
                    if(!stk.isEmpty()){
                        stk.remove(stk.size()-1);
                    }
                }
                else if (dots == 2){
                    while (i < n && path.charAt(i) != '/') {
                        crnt += path.charAt(i);
                        ++i;
                    }
                    stk.add(crnt);
                    
                }
                else if(dots > 2){
                    
                    while (i < n && path.charAt(i) != '/') {
                        crnt += path.charAt(i);
                        ++i;
                    }
                    stk.add(crnt);
                }

        }
            else {
                while (i < n && path.charAt(i) != '/') {
                    crnt += path.charAt(i);
                    ++i;
                }
                stk.add(crnt);
            }


        }
        return "/"+String.join("/",stk);
    }
}