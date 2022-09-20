#include <iostream>

class FooString{
    char *buf;
    int s_size;
public:
    FooString(char* tbuf){
        s_size = get_size(tbuf);
        
        buf = new char[s_size];
        for(int i=0; i<s_size; i++){
            buf[i] = tbuf[i];
        }
    }
    ~FooString(){
        delete []buf;
    }

    bool compare(FooString str){
        if(str.length() == this->length()){
            for(int i=0; i<s_size-1; i++){
                if (str[i] != buf[i])
                    return false;
            }
            return true;
        }
        return false;
    }
    bool compare(char* str){
        if(get_size(str) == s_size){
            for(int i=0; i<s_size-1; i++){
                if (str[i] != buf[i])
                    return false;
            }
            return true;
        }
        return false;
    }
    void add(FooString str){
        char *new_str = new char[s_size + str.length()];
        for(int i=0; i<s_size-1; i++){
            new_str[i] = buf[i];
        }
        for(int i=0; i<str.length(); i++){
            new_str[s_size - 1 + i] = str[i];
        }
        s_size += str.length();
        delete []buf;
        buf = new_str;
    }
    void add(char* str){
        char *new_str = new char[s_size + get_size(str)-1];
        for(int i=0; i<s_size-1; i++){
            new_str[i] = buf[i];
        }
        for(int i=0; i<get_size(str)-1; i++){
            new_str[s_size - 1 + i] = str[i];
        }
        s_size += get_size(str)-1;
        delete []buf;
        buf = new_str;
    }
    char & operator[] (int i)
    {   
        if (i < s_size){
            return buf[i];
        }
    }

    int length(){
        return s_size - 1;
    }

    void show(){
        if (buf)
            std::cout<<buf;
    }
    int get_size(char *tbuf){
        int t_size = 0;
        char b = tbuf[t_size];
        while(b!=0){
            t_size++;
            b = tbuf[t_size];
        }
        return t_size + 1;
    }
};

int main(){

    FooString str1("Hello");
    FooString str2("Hello Megane");
    str1.add(" Megane");
    str1.show();
    //str.show();
    std::cout<<"\n\n"<<str1.compare(str2)<<"\n";

}