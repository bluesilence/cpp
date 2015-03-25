class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty())
            return "/";
        
        stack<string> validPaths;
        int i = 0;
        int j = 0;
        int len = path.size();
        
        while (i < len) {
            while (i < len && path[i] == '/')
                i++;
            
            if (i < len) {
                j = i;
                while (j < len && path[j] != '/')
                    j++;
                
                string tmp = path.substr(i, j-i);
                if (tmp == ".") {
				        } else if (tmp == "..") {
					        if (!validPaths.empty())
						        validPaths.pop();
				        } else {
                  validPaths.push(tmp);
				        }

				        i = j + 1;
            }
        }
        
        return generatePath(validPaths);
    }

private:
    string generatePath(stack<string> &paths) {
        if (paths.empty())
            return "/";
            
        string path = "";
        while (!paths.empty()) {
            string tmp = paths.top();
            paths.pop();
            
            path = "/" + tmp + path;
        }
        
        return path;
    }
};
