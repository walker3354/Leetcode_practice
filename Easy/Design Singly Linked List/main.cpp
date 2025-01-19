#include <iostream>
#include <vector>
using namespace std;

struct link_node {
        int value;
        link_node *next;
};

class LinkedList {
    private:
        link_node *head;
        link_node *tail;
        int node_counter;

    public:
        LinkedList() {
            node_counter = 0;
            head = NULL;
            tail = NULL;
        }

        int get(int index) {
            if (index < 0 || index >= node_counter) return -1;
            link_node *temp = head;
            for (int i = 0; i < index; i++) temp = temp->next;
            return temp->value;
        }

        void insertHead(int val) {
            link_node *temp = new link_node;
            temp->value = val;
            if (head == NULL) {
                head = tail = temp;
                head->next = NULL;
            } else {
                temp->next = head;
                head = temp;
            }
            node_counter++;
        }

        void insertTail(int val) {
            link_node *temp = new link_node;
            temp->value = val;
            temp->next = NULL;
            if (tail == NULL)
                head = tail = temp;
            else {
                tail->next = temp;
                tail = temp;
            }
            node_counter++;
        }

        bool remove(int index) {
            if (index < 0 || index >= node_counter) return false;
            link_node *temp;
            if (index == 0) {
                temp = head->next;
                delete head;
                head = temp;
            } else {
                link_node *delete_node;
                temp = head;
                for (int i = 0; i < index - 1; i++) temp = temp->next;
                delete_node = temp->next;
                if (delete_node == tail) {
                    tail = temp;
                    temp->next = NULL;
                } else {
                    temp->next = delete_node->next;
                }
                delete delete_node;
            }
            node_counter--;
            return true;
        }

        vector<int> getValues() {
            vector<int> return_arr;
            link_node *temp = head;
            while (temp != NULL) {
                return_arr.push_back(temp->value);
                temp = temp->next;
            }
            return return_arr;
        }
};
