#include <iostream>
#include <string.h>
#include <LinkedList.h>

using namespace std;


class Hybrid
{
    LinkedList* List[26];
public:
    Hybrid()
    {
        for(int i =0; i<26; i++)
        {
            List[i]=NULL;
        }
    }
    int getIndex(char* _name)
    {
        int index = toupper(_name[0]);
        //check if first char not [A-Z]
        if(index < 65 || index > 90)
            return -1;
        index-=65;
        return index;
    }
    int append(int _id,char* _name)
    {
        int index = getIndex(_name);
        if (index == -1)
            return 0;
        if (List[index] == NULL)
            List[index] = new LinkedList;
        List[index]->append(_id,_name);
        return 1;
    }
    void display()
    {
        for(int i=0; i<26; i++)
        {
            if(List[i] != NULL)
            {
                cout<<(char)(i+65)<<endl;
                List[i]->display();
            }
        }
    }
    int get(char* _name,Node& _node)
    {
        int index = getIndex(_name);
        if (index == -1)
            return 0;
        else
        {
             if( List[index]->get(_name)==0)return 0;
             Node node( List[index]->get(_name)->id, List[index]->get(_name)->name);
            _node = node;
            return 1;
        }
    }
    int deleteNode(char* _name)
    {
        int index = getIndex(_name);
        if (index == -1)
            return 0;

        List[index]->deleteNode(_name);
    }

};
int main()
{
    Hybrid h;
    h.append(10,"peter");
    h.append(20,"salah");
    h.append(30,"samir");
    h.display();
    h.deleteNode("peter");
    h.display();
    Node node;
    if(h.get("samvir",node) == 0) cout<<"no node";
    return 0;
}
