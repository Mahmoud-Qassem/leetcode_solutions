class Solution {
    public boolean isValid(String s) {
        Deque<Character>st = new ArrayDeque<>();

        int sz = s.length();
        for(int i=0 ;i<sz;++i){
            if(!st.isEmpty()){
                Character top = st.peek();
                if(top=='(' && s.charAt(i)==')' || top=='{' && s.charAt(i)=='}' || top=='[' && s.charAt(i)==']'){
                    st.pop();
                }
                else{
                    st.push(s.charAt(i));
                }
            }
            else {
                st.push(s.charAt(i));
            }
        }
        if(st.isEmpty()){
            return true;
        }else{
            return false;
        }
        


    
    }
}