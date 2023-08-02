class FileSystem 
{
public:
  bool createPath(const string& path, int value) 
  {
    auto parent = path.substr(0, path.rfind('/'));
    if (!parent.empty() && !paths.count(parent)) return false;
    return paths.emplace(path, value).second;
  }
    
  int get(const string& path) 
  {
    auto it = paths.find(path);
    if (it == paths.end()) return -1;
    return it->second;
  }
  
private:
  unordered_map<string, int> paths;
};