int flag = 0;
        	int ind = x.ss.ss;
        	multiset<int> st = x.ss.ff;
        	if(strk[ind].size() > x.ss.ff.size()){
        		flag = 1;
        	}
        	if(strk[ind] > x.ss.ff){
        		flag = 1;
        	}
        	if(!flag && strk[ind].size() == st.size()){
        		multiset<int>::iterator it1 = st.begin(), it2 = strk[ind].begin();
        		while(it1 != st.end()){
        			if(*it1 < *it2){
        				flag = 1;
        				break;
        			}
        			it1++;
        			it2++;
        		}
        	}
        	if(cost[ind] > x.ff.ss)
        		flag = 1;
        	if(flag == 1){
        		if(cost[ind] >= x.ff.ss){
        			cost[ind] = x.ff.ss;
        			if(strk[ind].size() > x.ss.ff.size())
        				strk[ind] = st;
        			else if(strk[ind].size() == x.ss.ff.size()){
        				vector<pair<int, int> > upd;
        				multiset<int>::iterator it1 = st.begin(), it2 = strk[ind].begin();
        				while(it1 != st.end()){
        					if(*it1 < *it2){
        						upd.push_back({*it1, *it2});
        					}
        					it1++;
        					it2++;
        				}
        				for(int i = 0; i < upd.size(); i++){
        					strk[ind].erase(strk[ind].find(upd[i].ss));
        					strk[ind].insert(upd[i].ff);
        				}
        			}
        			for(auto a:adj[x.ss.ss]){
        			    int k1 = x.ff.ff;
        			    int cst = x.ff.ss;
        			    multiset<int> st = x.ss.ff;
        			    if(k1 < k){
        			        st.insert(a.ss);
        			    }
        			    else{
        			        int y = *st.begin();
        			        st.erase(st.find(y));
        			        st.insert(max(y, a.ss));
        			        cst += min(a.ss, y);
        			    }
        			    //cout << a.ff <<" "<<*st.begin() <<" " ;
        			    if(cost[a.ff] >= cst){
        			        cost[a.ff] = cst;
        			        //cout << a.ff;
        			        pair<pair<int, int>, pair<multiset<int>, int> > r = {{min(k1 + 1, k), cst}, {st, a.ff}};
        			        pq.push(r);
        			    }
        			}
        		}
        	}