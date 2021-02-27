#include<string>
#include <iostream>
#include <fstream>
using namespace std;
class node {
public:
    char symbol;
    int frequency;
    int assignedInt;
    string fibcode;
    node* next;
    node() { next = NULL; };
    node(char s) { symbol = s; next = NULL; };

}*first = NULL;
/*This function add the nodes to the end of the link list
it gets a pointer and the symbol of the node to be added to the link list*/
void InsertatEndLinkList(node** first, char symbol)
{
    node* newNode = new node(symbol);
    if (*first == NULL) //if the link list is empty
    {
        *first = newNode;
    }
    else
    {
        node* temp = *first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
//This Function display the link list by getting pointer to the head of if
void DisplayLinkList(node* head)
{
    if (head == NULL) //if the link list is empty.
        return;
    while (head != NULL)
    {
        cout << "Symbol: " << head->symbol << "," << " Frequency: " << head->frequency << ", Code: " << head->fibcode << endl;
        head = head->next;
    }
}
/*This function gets the original string and special char as inputs and returns the frequency
of the special character*/
void CreateLinkList(string OriginalString) //This function gets my original string and create a link list from it
{
    string::iterator i;
    for (i = OriginalString.begin(); i != OriginalString.end(); i++)
    {
        InsertatEndLinkList(&first, *i); //using the function to add the new node to the end of link list.
    }
}
/*The SortedMerge, FrontBackSplit and MergeSort are GeeksForGeeks code I did a little change in it*/
/*These three functions being used to sort link list based on one factor*/
node* SortedMergeF(node* a, node* b)
{
    node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->frequency > b->frequency) {
        result = a;
        result->next = SortedMergeF(a->next, b);
    }
    else if (a->frequency == b->frequency && a->symbol > b->symbol)
    {
        result = a;
        result->next = SortedMergeF(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMergeF(a, b->next);
    }
    return (result);
}
node* SortedMergeS(node* a, node* b)
{
    node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->symbol < b->symbol) {
        result = a;
        result->next = SortedMergeS(a->next, b);
    }
    else if (a->symbol == b->symbol)
    {
        result = a;
        result->next = SortedMergeS(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMergeS(a, b->next);
    }
    return (result);
}
void FrontBackSplit(node* source, node** frontRef, node** backRef)
{
    node* fast;
    node* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
void MergeSortF(node** headRef)
{
    node* head = *headRef;
    node* a;
    node* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSortF(&a);
    MergeSortF(&b);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMergeF(a, b);
}
void MergeSortS(node** headRef)
{
    node* head = *headRef;
    node* a;
    node* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSortS(&a);
    MergeSortS(&b);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMergeS(a, b);
}
/*This Function gets the file input and special charactor and return frequency of it*/
int FrequencyFunc(string myString, char specialCharacter)
{
    int count = 0; //this the counter which returns at the end of the function
    string::iterator i;
    for (i = myString.begin(); i != myString.end(); i++)
    {
        if (*i == specialCharacter) //comparing each character in myString with specialCharacter
            count++;
    }
    return count;
}
/*This function recieves data from the file and assigned the frequency to each symbol*/
void AssignedFrequency(string myString)
{
    node* temp = first;
    while (temp != NULL)
    {
        temp->frequency = FrequencyFunc(myString, temp->symbol);
        temp = temp->next;
    }
}
/*This function used after sorting link list based of its frequency to assign an interger to each node*/
void AssignedIntFunc(node** head)
{
    node* temp = *head;
    int counter = 1;
    while (temp)
    {
        temp->assignedInt = counter++;
        temp = temp->next;
    }
}
string CreateFibCode(int i[], int n)
{
    string result;
    int x = i[0] - 2;
    for (int j = 0; j <= x; j++)
    {
        result += "0";
    }
    result[x] = '1';
    int z = 1;
    while (z < n)
    {
        x = i[z] - 2;
        if (x < -1)
            break;
        if (x == -1)
        {
            result[0] = '1';
            break;
        }
        if (result[x + 1] != '1' && result[x - 1] != '1')
        {
            result[x] = '1';
        }
        z++;
    }
    return result + "1";
}

//This table will contain Fibonacci numbers.
int fibTable[10] = { 0 };
/*This Function recursively calculate fibonacci number*/
int RecursiveFibFunction(int n)
{
    if (n <= 1)
        return n;
    else
        return RecursiveFibFunction(n - 2) + RecursiveFibFunction(n - 1);
}
/*this function fill out the fibonacci table*/
void FillFibTable()
{
    for (int i = 1; i < 10; i++)
    {
        fibTable[i] = RecursiveFibFunction(i);
    }
}
/*FindClosesFibNum gets a number and return closes fibonacci number equal or smaller than the original number*/
int FindClosesFibNum(int n)
{
    int i = 0;
    while (n >= fibTable[i])
        i++;
    return fibTable[i - 1];
}
/*FindFibIndex gets a number and return the index of closes fibonacci number equal or smaller than the original number*/
int FindFibIndex(int n)
{
    int i = 1;
    while (n != fibTable[i])
    {
        i++;
    }
    return i;
}
/*GenerateFibCode gets a integer and return its fibonacci code word for it*/
string GenerateFibCode(int n)
{
    if (n == 1)
        return "11";
    int reminder = n;
    int i[10] = { 0 };
    int x = 0;
    int j = 0;
    while (reminder != 0)
    {
        reminder = n - FindClosesFibNum(n);
        i[j++] = FindFibIndex(FindClosesFibNum(n));
        n = reminder;
    }
    return CreateFibCode(i, j);
}
/*AssignedFibCode gets a pointer to the link list and assign fibonacci code word to each node*/
void AssignedFibCode(node** head)
{
    node* temp = *head;
    while (temp)
    {
        temp->fibcode = GenerateFibCode(temp->assignedInt);
        temp = temp->next;
    }
}

int main()
{
    string fileName; //name of the file that I have to read
    string originalString; //originalstring which is gonna be repeated in file
    getline(cin, originalString);
    getline(cin, fileName);
    string data; //this variable contains the file's string
    ifstream inputFile;
    inputFile.open(fileName);
    if (inputFile.is_open())
        inputFile >> data;
    inputFile.close();
    CreateLinkList(originalString);
    AssignedFrequency(data);
    MergeSortF(&first);//second pointer refers to the sorted linked list base on frequency
    AssignedIntFunc(&first);
    FillFibTable();
    AssignedFibCode(&first);
    MergeSortS(&first);
    DisplayLinkList(first);
}


