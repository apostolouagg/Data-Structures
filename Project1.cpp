#include <iostream>
#include <random>
#include <functional>
#include <ctime>
#include <cstdlib>

//gia thn 1h linked list
struct node
{
    int data; //data node
    node* next; //node next
};

//gia thn 2h linked list
struct output
{
    int data; //data node
    output* next; //node next
};

int plListwn; //plhthos twn listwn

int main()
{
    std::cout << "Poses listes thelete? : " ;
    std::cin >> plListwn;
    int plListwn2 = plListwn; //to bazoyme kai se allh mia metablhth (plListwn2) giati h plListwn sthn parakatw epanalhpsh meiwnetai, alla to plhthos twn listwn tha mas xreiastei kai pio meta

    srand(time(0)); //random me to xrono dld sxedon pragmatika random

    node* n; //xreishmopoieitai new nodes
    node* HEADS[plListwn]; //array pou xreishmopoieitai gia na apothikeuei ta head twn linked lists
    node* temp; //xreishmopoieitai gia na ennonei ta nodes

    while(plListwn > 0) //oso exoume akoma listes
    {
        int list_size = 1+(rand()%10); //random list size apo to 1 ews kai to 10

        n = new node(); //neo node
        n->data = 0+(rand()%30); //random arithmos gia to data tou node apo to 0 ews kai to 30
        temp = n; //to temp deixnei ekei pou deixnei ekei pou deixnei kai to n
        HEADS[plListwn] = n; //to HEADS[plListwn] (head tou node) deixnei ekei pou deixnei kai to n

        for(int i = 0; i < list_size; i++) //gia megethos ths listas
        {
            n = new node(); //neo node
            n->data = 0+(rand()%30); //random arithmos gia to data tou node apo to 0 ews kai to 30
            temp->next = n; //sunesh prohgoumenou node me to kainourgio node. Dld to next to bazoume na deixnei ekei pou deixnei to n. Alla gia na elegksoume thn timh tou next xreiazomaste to temp pou deixnei sto
                            //next tou prohgoumenou node.
            temp = temp->next; //bazouem kai to temp na deixnei sto kainourgio node
        }
        n->next = NULL; //bazoume to teleutaio stoixeio null

        //emfanish linked list
        node* p = HEADS[plListwn];
        while(p != NULL)
        {
            std::cout << p->data << " -> " ;
            p = p->next;
        }
        std::cout << "NULL" << "\n";

        plListwn--;
    }


    /*                 ΕΔΩ                 */


    node* firstpointer; //"krataei" 1 arithmo kathe fora
    node* secondpointer; //pernaei apo oles tis listes kai sugkrinetai me ton firstpointer

    //gia th 2h linked list
    output* newnode; //xreishmopoieitai new nodes
    output* t; //xreishmopoieitai gia na ennonei ta nodes
    output* head; //xreishmopoieitai gia na apothikeuei to head ths linked list

    bool countIt; //an einai true tote metraei ton arithmo alliws apla ton diagrafei. auto ginetai gia na mhn metrhthei o idios arithmos 2 h parapanw fores se periptwsh pou autos uparxei 2 h parapanw fores sthn idia lista
    bool headMatter = true; //tsekarei an eimaste sto head ths kainourgias linked lists h oxi

    int counter; //metraei poses fores uparxei enas arithmos
    int positionFirst = 1; //thesh tou 1ou pointer
    int positionSecond = 1; //thesh 2ou pointer
    int howManyNulls = 0; //metraei posa NULL exei sunanthsei. Dld poses listes exei elegksei oloklhres
    int plListwn3 = plListwn2; //to plListwn3 tha meiwnetai, tha ekshghthei parakatw

    for(int i = 0; i < plListwn2-1; i++) //plListwn2-1 giati koitame kai to teleutaio bazontas +1
    {
        countIt = true;
        counter = 1; //an to brei tote uparxei 2 fores, mia sto firstpointer kai mia sto second pointer. Opote to bazoume na ksekinaei apo 1
        firstpointer = HEADS[i]; //to stoixeio pou elegxoume to deixnei o 1os pointer
        
        positionFirst = 1; //h thesh tou node sto opoio einai o 1os pointer
        secondpointer = firstpointer->next; //ena bhma mprosta apo to first pointer

        while(firstpointer != NULL)
        {
            while(secondpointer != NULL)
            {
                if((firstpointer->data == secondpointer->data) && countIt) //an brethei o idios arithmos kane count kai delete
                {
                    counter++; //count

                    //delete
                    //xreishmopoioume 2 temporary pointers
                    node* temp1  = HEADS[i]; //to temp1 ousiastika deixnei ekei pou deixnei kai o firstpointer
                    node* temp2;

                    if(positionSecond == 1) //an h thesh einai 1 dld an briskomaste sto head mias linked list
                    {
                        temp2 = secondpointer; //to temp2 deixnei ekei pou deixnei kai o secondpointer
                        secondpointer = temp1->next; //metakinoume ton secondpointer sto epomeno node
                        delete temp2; //diagrafoume to node
                    }
                    else //an den eimaste sto head mias linked list
                    {
                        for(int j = 0; j < positionSecond-2; j++) //me thn epanalhpsh auth bazoume to temp1 (pou ksekinaei apo to head ths linked list) na ftasei 1 thesh prin to node pou theloume na diagrapsoume
                        {
                            temp1 = temp1->next;
                        }
                        temp2 = temp1->next; //bazoume to temp2 na deixnei to node pou theloume na diagrapsoume
                        secondpointer = temp2->next; //bazoume ton secondpointer na deixnei to epomeno node apo auto pou theloume na diagrapsoume
                        delete temp2; //diagrafoume to node
                    }

                    countIt = false; //kanoume to countIt==false gia to logo pou ekshghsame prin
                }
                else if (firstpointer->data == secondpointer->data) //an brethei ksana o idios arithmos kane apla delete
                {
                    //delete
                    //idia diadikasia
                    node* temp1  = HEADS[i];
                    node* temp2;
                    if(positionSecond == 1)
                    {
                        temp2 = secondpointer;
                        secondpointer = temp1->next;
                        delete temp2;
                    }
                    else
                    {
                        for(int j = 0; j < positionSecond-2; j++)
                        {
                            temp1 = temp1->next;
                        }

                        temp2 = temp1->next;
                        secondpointer = temp2->next;
                        delete temp2;
                    }
                }
                
                secondpointer = secondpointer->next; //paei sto epomeno node
                positionSecond++; //profanws proxwrame kai to position
            }


            howManyNulls++; //metraei posa null exei sunanthsei, dhladh ousiastika poses linked lists exei elegksei

            if(howManyNulls == plListwn3) //an exei brei osa nulls oses oi listes shmainei exei elegksei oles tis listes
            {
                if(counter >= plListwn2 / 2) //an o arithmos pou psaxname uparxei se toulaxiston tis mises listes
                {
                    if(headMatter) //an briskomaste sto head ths kainourgias (telikhs) linked list
                    {
                        headMatter = false; //false gia na mhn ksanampei edw
                        
                        //idia diasikasia me parapanw
                        newnode = new node2();
                        newnode->data = firstpointer->data;
                        t = newnode;
                        head = newnode;
                    }
                    else //an den eimaste sto head
                    {
                        //idia diasikasia me parapanw
                        newnode = new node2();
                        newnode->data = firstpointer->data;
                        t->next = newnode;
                        t = t->next;
                    }

                    //emfanish linked list
                    node2* p = head;
                    while(p != NULL)
                    {
                        std::cout << p->data << " -> " ;
                        p = p->next;
                    }
                    std::cout << "NULL" << "\n";  
                }

                node* fpnext = firstpointer->next; //pointer pou koitaei to epomeno tou firstpointer
                fpnext = fpnext->next; //paei sto methepomeno tou firstpointer
                counter = 1; //kanoume to counter reset sto 1

                if(firstpointer->next == NULL) //an to epomeno tou firstpointer einai null (dld teleiwsame me mia linked list)
                {
                    firstpointer = firstpointer->next; //proxwraei
                    howManyNulls = 0; //to kanoume 0 giati pame na elegksoume neo stoixeio se oles tis listes
                    plListwn3--; //meiwnetai kata 1 giati an mpoume edw shmainei oti tsekarame 1 oloklhrh lista. Kai afou to secondpointer einai panta mprosta apo to firstpointer tote tha tsekarei 1 ligoterh lista
                                 //kathe fora pou to firstpointer ftanei se NULL (dld sto telos mias listas)
                }
                else if(fpnext == NULL) //an to methepomeno tou firstpointer einai null
                {
                    firstpointer = firstpointer->next; //proxwraei
                    positionFirst++; //h thesh tou node sto opoio einai o 1os pointer
                    secondpointer = HEADS[i+1]; //paei sthn epomenh linked list ksekinwntas apo to head ths to opoio brisketai sto array
                    positionSecond = 1; //h thesh ginetai 1 giati phgame se kainourgia linked list
                    howManyNulls = 0; //to kanoume 0 giati pame na elegksoume neo stoixeio se oles tis listes
                }
                else
                {
                    firstpointer = firstpointer->next; //proxwraei
                    positionFirst++; //h thesh tou node sto opoio einai o 1os pointer
                    secondpointer = firstpointer->next; //panta to secondpointer einai mprosta apo to firstpointer
                    positionSecond = positionFirst +1; //h thesh tou node sto opoio einai o 2os pointer
                    howManyNulls = 0; //to kanoume 0 giati pame na elegksoume neo stoixeio se oles tis listes
                }
            }
            else
            {
                secondpointer = HEADS[i+1]; //paei sthn epomenh linked list ksekinwntas apo to head ths to opoio brisketai sto array
                positionSecond = 1; //h thesh sinetai 1 giati phgame se kainourgia linked list
            }
        }
    }

    return 0;
}