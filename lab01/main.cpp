#include "iostream"
#include "string"

using namespace std;

struct Item {
    string type;
    int quantity;
    double price;

    bool operator==(const Item &other) const {
        return (type == other.type && quantity == other.quantity && price == other.price);
    }
    bool operator!=(const Item &other) const {
        return !(*this == other);
    };
    Item(string type, int quantity, double price) : type(type), quantity(quantity), price(price){}
};

struct Node{
    Item item;
    Node *next;
    Node(Item item) : item(item), next(nullptr){}
};

class List{
private:
    Node *head;
    Node* tail;
public:
    List(){
        head = nullptr;
        tail = nullptr;
    }
    void AddFirst (Item item)
    { Node *NewNode = new Node(item);
        NewNode->next = head;
        head = NewNode;
        return;
    }

    void AddLast (Item item) {
        Node *tmp = head;
        if (head == NULL) {
            AddFirst(item);
            return;
        }
        while (tmp->next) tmp = tmp->next;
        Node *NewNode = new Node(item);
        NewNode->next = NULL;
        tmp->next = NewNode;
        return;
    }
    int AddAfter(Item item, Item targetItem)
    { if ( head == NULL )return 1;
        Node *tmp = head;
        while(tmp != NULL && tmp->item != targetItem)
            tmp = tmp->next;
        if ( tmp == NULL )return 1;
        Node *NewNode = new Node(item);
        NewNode->next = tmp->next;
        tmp->next = NewNode;
        return 0;
    }
    int AddBefore( Item item, Item TargetItem){
        head = this->head;
        if ( head == NULL )return 1;
        if (head->item == TargetItem){
            AddFirst(item); return 0;
        }
        if ( head->next == NULL )return 1;
            Node *prev = head, *tmp = head->next;
            while(tmp->next!=NULL && tmp->item!=TargetItem)
            { prev = prev->next; tmp = tmp->next; }
            if ( tmp->next==NULL && tmp->item!=TargetItem)
                return 1;
            Node *NewNode = new Node(item);
            NewNode->next = tmp;
            prev->next = NewNode;
            return 0;
        }
        int DelNode(Item DelItem)
        { if ( head == NULL )return 1;
        Node *tmp = head;
        if ( head->item == DelItem )
        { head = head->next; delete tmp; return 0;}
        if ( head->next == NULL )return 1;
        Node *prev = head; tmp = head->next;
        while(tmp->next != NULL && tmp->item != DelItem)
        { prev = prev->next; tmp = tmp->next; }
        if ( tmp->next==NULL && tmp->item!= DelItem)
            return 1;
        prev->next = tmp->next;
        delete tmp;
        return 0;
    }
    void PrintList(){
        if ( head == NULL )
        { cout<<"The list is empty"; return; }
        Node *tmp = head;
        while(tmp != NULL)
        { cout<<"Product: "<<tmp->item.type<<
              "\nAmount: "<<tmp->item.quantity<<
              "\nPrice: "<<tmp->item.price<<"\n\n";
            tmp = tmp->next;
        }
        return;
    }
};

int main(){
    Item item1 = Item("Table", 20, 50.0);
    Item item2 = Item("Chair", 10, 30.0);
    Item item3 = Item("Lamp", 25, 15.5);
    Item item4 = Item("Pencil", 30, 5.4);
    List list = List();
    list.AddFirst(item1);
    list.AddLast(item2);
    list.AddAfter(item3, item1);
    list.AddBefore(item4, item3);
    list.PrintList();
    cout << "–––" << endl;
    list.DelNode(item2);
    list.PrintList();
    return 0;
}