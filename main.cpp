/*
priest vs killer
written by Its Mahdi! :)

plz ream REAME before using this code
*/

#include <iostream>
#include <vector>
using namespace std;

class state_node 
{
public:
	int priest, // number of priest on the right side
	killer; // number of killer on the right side in the current state
	int boat; // this varibable shows the location of boat
			  // if boat = -1 so boat is on the left side and 
			  //if boat=1, boat is on the right side
	
	state_node *parent; // pointer of parents stae (action of befor the current state)

	state_node (state_node *parent_link=NULL,int number_of_priest = -1,int number_of_killer = -1, int boat_loc = 0)
	{
		priest = number_of_priest;
		killer = number_of_killer;
		boat = boat_loc;
		parent = parent_link;

	}
};

class search 
/* this class will make a tree with logical states
and sreaching on the tree to find the goal state
it will search in BFS or DFS mode
*/
{
public:
	int n; // number of killer and number of priest at the begining
	state_node *start_state;
	vector<state_node *> state_list;

	search(int number) 
	{
		n = number;
		start_state = new state_node(NULL,n,n,1);
	}

	state_node* LIFO (); //searching for goal state with last in first out strategy
	state_node* FIFO (); //searching for goal state with first in first out strategy

	// LIFO is DFS search and FIFO is BFS strategy
};
/////////////////////////////////////////////////////////
state_node* search::FIFO()
{
	state_list.push_back(start_state);
	long int count=0;
	while (state_list.size()>0)
	{
		count ++;
		cout<<"size = "<<state_list.size()<<endl;
		state_node *next_state;
		state_node *current_state;
		current_state = state_list.front();
		state_list.erase(state_list.begin());
		//state_list.pop_back();
		cout<<"size2 = "<<state_list.size()<<endl;
		cout<<"priest= "<<current_state->priest<<" killer= "<<current_state->killer<<endl<<"boat= "<<current_state->boat<<endl;
		if ( current_state->priest==0 && current_state->killer==0 )
		{
			cout<<"goal state founded";
				cout<<"***"<<count<<"***";

			return current_state;
			exit;
		} else
			{
				if (current_state->boat==1) // this part will do the actins when the boat is on the right side
				{
					cout<<"injaaaaaaaaaaaaaaaaaa"<<endl;
					if (current_state->priest -2 >= 0 )  //bringing 2 priest to the left
					{
						next_state = new state_node(current_state,current_state->priest -2,current_state->killer,-1);
						if (next_state->priest <= next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (current_state->killer -2 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest,current_state->killer -2,-1);
						if (next_state->priest <= next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (current_state->priest -1 >=0 && current_state->killer -1 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest -1,current_state->killer -1,-1);
						if (next_state->priest <= next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (current_state->priest -1 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest -1,current_state->killer,-1);
						if (next_state->priest <= next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (current_state->killer -1 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest,current_state->killer-1,-1);
						if (next_state->priest <= next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
				}
				if (current_state->boat== -1) // this part will do the actins when the boat is on the left side
				{
					cout<<"oooooooonja"<<endl;
					if (n - current_state->priest -2 >= 0 ) //bringing 2 priest to the right side
					{
						next_state = new state_node(current_state,current_state->priest +2,current_state->killer, 1);
						if (next_state->priest <= next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (n - current_state->killer -2 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest,current_state->killer +2, 1);
						if (next_state->priest <= next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (n - current_state->priest -1 >=0 && n - current_state->killer -1 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest +1,current_state->killer +1, 1);
						if (next_state->priest <= next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (n - current_state->priest -1 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest +1,current_state->killer, 1 );
						if (next_state->priest <= next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (n - current_state->killer -1 >= 0 ) 
					{
						next_state = new state_node(current_state,current_state->priest,current_state->killer+1, 1);
						if (next_state->priest <= next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
				}
			}

	}
}
////////////////////////



int main ()
{
	class search *condition;
	condition = new search(2);

	state_node *ans = condition->FIFO();

	cout<<endl<<ans->boat<<"	"<<ans->killer;


	return 0;
}
