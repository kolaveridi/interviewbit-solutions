	struct node{
		  string word;
		  int len;
		};
	
		bool adjacent(string s,string t){
			int c=0;
			int n=s.size();
			for(int i=0;i<n;i++){
				if(s[i]!=t[i])
				c++;
			}
			if(c>1 )
			 return false;
			 else
			 return true;
			
		}
 int  bfs(string &start, string &target, set <string> &dict){
			queue <node> q;
			node first;
			first.word=start;
			first.len=1;
			q.push(first);
			while(!q.empty()){
				node cur=q.front();
				q.pop();
				set <string>::iterator it;
				for(it=dict.begin();it!=dict.end();it++){
					// check if current word and the word in dictionary are adjacent 
					string temp=*it;
					if(adjacent(temp,cur.word)){
				 first.word=temp;
				first.len=cur.len+1;
						q.push(first);
					dict.erase(temp);
					if(temp==target)
					return first.len;
					
					
				}
			}
		}
		return 0;
	}
int Solution::ladderLength(string start, string target, vector<string> &dictV) {
    if(start==target)
    return 1;
     set <string> dict;
    
	 for(int i=0;i<dictV.size();i++){
	 	string x=dictV[i];
	 	dict.insert(x);
	 }
	  int ans=	bfs(start,target,dict);
	     	return ans;
	 
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
