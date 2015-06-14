class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty())
            return path;
        
        stack<string> actualPaths;
        
        int begin = 0;
        int end = 0;
        
        while (begin < path.size()) {
            while (begin < path.size() && path[begin] == '/') {
                begin++;
            }
            
            if (begin < path.size()) {
                end = begin;
                while (end < path.size() && path[end] != '/') {
                    end++;
                }
                
                string subPath = path.substr(begin, end - begin);
                
                if (subPath == "..") {
                    if (!actualPaths.empty()) {
                        actualPaths.pop();
                    }
                } else if (subPath == ".") {
                    //Do nothing
                } else {
                    actualPaths.push(subPath);
                }
                
                begin = end;
            }
        }
        
        return combinePaths(actualPaths);
    }

private:
    string combinePaths(stack<string> &paths) {
        string result = "";
        
        while (!paths.empty()) {
            string path = paths.top();
            paths.pop();
            
            result = "/" + path + result;
        }
        
        if (result.empty())
            return "/";
        else
            return result;
    }
};
