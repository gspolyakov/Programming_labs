//#include "iostream"
//#include "string"
//
//using namespace std;
//
//struct Item {
//    string type;
//    int quantity;
//    double price;
//
//    bool operator==(const Item &other) const {
//        return (type == other.type && quantity == other.quantity && price == other.price);
//    }
//    bool operator!=(const Item &other) const {
//        return !(*this == other);
//    };
//    Item(string type, int quantity, double price) : type(type), quantity(quantity), price(price){}
//};
//
//struct Node{
//    Item item;
//    Node *next;
//    Node(Item item) : item(item), next(nullptr){}
//};
//
//class List{
//private:
//    Node *head;
//    Node* tail;
//public:
//    List(){
//        head = nullptr;
//        tail = nullptr;
//    }
//
//    int addFirst (Item item){
//        Node *NewNode = new Node(item);
//        NewNode->next = head;
//        head = NewNode;
//        return 0;
//    }
//
//    int addLast (Item item) {
//        Node *tmp = head;
//
//        if (head == NULL) {
//            addFirst(item);
//            return 0;
//        }
//
//        while (tmp->next) tmp = tmp->next;
//
//        Node *NewNode = new Node(item);
//        NewNode->next = nullptr;
//        tmp->next = NewNode;
//
//        return 0;
//    }
//
//    int addAfter(Item item, Item targetItem){
//
//        if ( head == NULL )return 1;
//
//        Node *tmp = head;
//
//        while(tmp != NULL && tmp->item != targetItem)
//            tmp = tmp->next;
//
//        if ( tmp == NULL )return 1;
//
//        Node *NewNode = new Node(item);
//        NewNode->next = tmp->next;
//        tmp->next = NewNode;
//
//        return 0;
//    }
//
//    int addBefore( Item item, Item TargetItem){
//        head = this->head;
//
//        if ( head == NULL )return 1;
//
//        if (head->item == TargetItem){
//            addFirst(item); return 0;
//        }
//
//        if ( head->next == NULL ) return 1;
//        Node *prev = head, *tmp = head->next;
//
//        while(tmp->next!=NULL && tmp->item!=TargetItem){
//            prev = prev->next; tmp = tmp->next;
//        }
//
//        if ( tmp->next==NULL && tmp->item!=TargetItem)
//            return 1;
//
//        Node *NewNode = new Node(item);
//        NewNode->next = tmp;
//        prev->next = NewNode;
//
//        return 0;
//    }
//
//    int delNode(Item delItem){
//        if ( head == NULL )return 1;
//        Node *tmp = head;
//
//        if ( head->item == delItem ){
//            head = head->next; delete tmp; return 0;}
//
//        if ( head->next == NULL ) return 1;
//        Node *prev = head; tmp = head->next;
//
//        while(tmp->next != NULL && tmp->item != delItem)
//        { prev = prev->next; tmp = tmp->next; }
//
//        if ( tmp->next==NULL && tmp->item!= delItem)
//            return 1;
//
//        prev->next = tmp->next;
//        delete tmp;
//
//        return 0;
//    }
//    void printList(){
//        if ( head == NULL )
//        { cout<<"The list is empty"; return; }
//        Node *tmp = head;
//        while(tmp != NULL)
//        { cout<<"Product: "<<tmp->item.type<<
//              "\nAmount: "<<tmp->item.quantity<<
//              "\nPrice: "<<tmp->item.price<<"\n\n";
//            tmp = tmp->next;
//        }
//        return;
//    }
//};
//
//int main(){
//
//    Item item1 = Item("Table", 20, 50.0);
//    Item item2 = Item("Chair", 10, 30.0);
//    Item item3 = Item("Lamp", 25, 15.5);
//    Item item4 = Item("Pencil", 30, 5.4);
//
//    List list = List();
//
//    list.addFirst(item1);
//    list.addLast(item2);
//    list.addAfter(item3, item1);
//    list.addBefore(item4, item3);
//    list.printList();
//
//    cout << "–––" << endl;
//
//    list.delNode(item2);
//    list.printList();
//
//    return 0;
//}