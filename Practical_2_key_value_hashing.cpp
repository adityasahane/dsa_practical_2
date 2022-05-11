#include<iostream>
using namespace std;

struct Node
{
    string name;
    string number;
    struct Node *next;
};

void add_chain(struct Node **chain, int index, string name, string number)
{
    struct Node *new_node = new struct Node();
    new_node->name = name;
    new_node->number = number;
    new_node->next = NULL;

    if(chain[index] == NULL)
    {
        chain[index] = new_node;
    }
    else
    {
        struct Node *ptr = chain[index];
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

void print_hashtable(string *actual_hastable_names, string *actual_hastable_number, struct Node **chain, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<i<<") ";
        if(actual_hastable_names[i] != "nothing")
        {
            cout<<actual_hastable_names[i]<<" "<<actual_hastable_number[i];
            if(chain[i] != NULL)
            {
                struct Node *ptr = chain[i];
                while(ptr != NULL)
                {
                    cout<<" --> "<<ptr->name<<" "<<ptr->number;
                    ptr = ptr->next;
                }
            }
        }
        cout<<endl;
    }
    cout<<endl;
}



int hash_function(int sum, int size)
{
    return sum % size;
}

int main()
{
    int n;
    cout<<"Enter Number of Person: ";
    cin>>n;

    string names[n];
    string number[n];
    int ascii_sum[n];
    string actual_hastable_names[n];
    string actual_hastable_number[n];
    struct Node *chain[n];

    for(int i = 0; i < n; i++)
    {
        cout<<"Enter Name of Person "<<i+1<<" : ";
        cin>>names[i];

        cout<<"Enter Number of Person "<<i+1<<" : ";
        cin>>number[i];

        actual_hastable_names[i] = "nothing";
        chain[i] = NULL;
    }

    for(int i = 0; i < n; i++)
    {
        int ind = 0;
        char c;
        ascii_sum[i] = 0;

        while(names[i][ind] != '\0')
        {
            c = names[i][ind];
            ascii_sum[i] += (int)c;
            ind++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        int index = hash_function(ascii_sum[i], n);
        // cout<<names[i]<<" will be stored at "<<index<<endl;

        if(actual_hastable_names[index] == "nothing")
        {
            actual_hastable_names[index] = names[i];
            actual_hastable_number[index] = number[i];
        }
        else
        {
            add_chain(chain, index, names[i], number[i]);
        }
    }

    cout<<"\n\n\n";

    print_hashtable(actual_hastable_names, actual_hastable_number, chain, n);

    // for(int i = 0; i < n; i++)
    // {
    //     cout<<actual_hastable_names[i]<<endl;
    //     cout<<actual_hastable_number[i]<<endl<<endl;
    // }

    return 0;
}