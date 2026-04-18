class LinkedList {
public:
    struct Node{
        int val;
        Node * next;
        Node(int val) : val(val), next(nullptr) {}
    };
    Node * head;
    Node * tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    ~LinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    Node* getNode(int index) {
    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
        if (curr == nullptr)
            return nullptr;
        }
        return curr;        
    }

    int get(int index) {
        Node * curr = getNode(index);
        return curr != nullptr ? curr->val : -1;
}

    void insertHead(int val) {
        Node* node = new Node(val);
        if(head == nullptr){
            tail = node;
        }
        node->next = head;
        head = node;
    }
    
    void insertTail(int val) {
        if (head == nullptr) {
            insertHead(val);
            return;
        }
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
        }

    bool remove(int index) {
        if (head == nullptr)  return false;
        if (index == 0) {
            head = head->next;
            if (head == nullptr)
                tail = nullptr;
            return true;
        }
        Node* before = getNode(index - 1);
        if (before == nullptr || before->next == nullptr) return false;
        if (before->next == tail)
            tail = before;
        before->next = before->next->next;
        return true;
    }

    vector<int> getValues() {
        Node * curr = head;
        vector<int> values;
        while(curr != nullptr){
            values.push_back(curr->val);
            curr = curr->next;
        }
        return values;
    }
};
