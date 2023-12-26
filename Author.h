#include <iostream>
#include <string>
using namespace std;

class Node
{

public:
  int data;
  // struct data
  //{
  //	int id;
  //	string name;
  //	int countOfBooks;
  //	string typeOfCategory;
  //	int size;
  //	string *namesOfBooks = new string[size];
  // };
  Node *next;
};
class Author
{
public:
  Node *head;
  Author()
  {
    head = NULL;
  }
  bool isEmpty()
  {
    return (head == NULL);
  }
  void insertFirst(int newItem)
  {
    Node *newnode = new Node();
    newnode->data = newItem;
    if (isEmpty())
    {
      newnode->next = NULL;
      head = newnode;
    }
    else
    {
      newnode->next = head;
      head = newnode;
    }
  }
  void display()
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
  }
  int count()
  {
    int counter = 0;
    Node *temp = head;
    while (temp != NULL)
    {
      counter++;
      temp = temp->next;
    }
    return counter;
  }
  bool isfound(int item)
  {
    Node *temp = head;
    while (temp != NULL)
    {
      if (temp->data == item)
        return true;
      temp = temp->next;
    }
    return false;
  }
  void insertBefore(int item, int newvalue)
  {
    if (isEmpty())
    {
      insertFirst(newvalue);
    }
    else
    {
      if (isfound(item))
      {
        Node *newnode = new Node();
        newnode->data = newvalue;
        Node *temp = head;
        while (temp != NULL && temp->next->data != item)
        {
          temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
      }
      else
      {
        cout << "Sorry, Item Not Found \n";
      }
    }
  }
  void Append(int newValue)
  {
    Node *newNode = new Node();
    newNode->data = newValue;
    Node *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
  }
  void Delete(int item)
  {
    if (isEmpty())
    {
      cout << "List is empty , no items to delete \n";
    }
    else
    {
      Node *temp = head;
      Node *delNode = head;
      if (head->data == item)
      {
        head = head->next;
        delete delNode;
      }
      else
      {
        Node *prev = NULL;
        while (delNode->data != item)
        {
          prev = delNode;
          delNode = delNode->next;
        }
        prev->next = delNode->next;
        delete delNode;
      }
    }
  }
};
void main()
{
  Author list;
  if (list.isEmpty())
  {
    cout << "The List Is Empty" << endl;
  }
  else
  {
    cout << "The List Contains " << list.count() << endl;
  }
  int item;
  cout << "Enter Item To Insert In The List \n";
  cin >> item;
  list.insertFirst(item);
  list.display();
  cout << "Enter Item To Insert In The List \n";
  cin >> item;
  list.insertFirst(item);
  list.display();
  cout << "Enter Item To Insert In The List \n";
  cin >> item;
  list.insertFirst(item);
  list.display();
  cout << "The List Contains " << list.count() << endl;
  cout << "Enter Item To Search For \n"
       << endl;
  cin >> item;
  if (list.isfound(item))
  {
    cout << "Item Found" << endl;
  }
  else
  {
    cout << "Item Is Not Found" << endl;
  }
  // cout << "Enter the new value and Item is that will insert before it \n";
  // int newvalue;
  // cin >> item >> newvalue;
  // list.insertBefore(item, newvalue);
  // list.display();

  // int newvalue;
  // cout << "Enter the new value for append\n";
  // cin >> newvalue;
  // list.Append(newvalue);
  // list.display();

  cout << "Enter the item to delete\n";
  cin >> item;
  list.Delete(item);
  list.display();
}