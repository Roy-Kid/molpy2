import molpy2.molcpp as cpp
class Atom(cpp.atom.Atom):
    
    def set(self, key, value):
        self[key] = value

    def get(self, key):
        return self[key]
    
    def __contains__(self, key):
        return self.has(key)
    
    def __hash__(self):
        return self.get_id()