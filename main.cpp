/*
priest vs killer
written by Its Mahdi! :)

plz read REAME before using this code
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

	void show_state()
	{
		cout<< "priest = "<<priest<<"\tkiller = "<<killer<<"\t boat = "<<boat<<endl;
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
	state_node *goal_state;
	vector<state_node *> state_list;

	search(int number) 
	{
		n = number;
		goal_state=NULL;
		start_state = new state_node(NULL,n,n,1);
	}
	void show_the_path_of_goal_state(state_node *goal)
	{
		while(goal != NULL)
		{
			goal->show_state();
			goal = goal->parent;
		}
	}
	void action_state(state_node *); // it will find the possible move from each state and add that to vector state list
	state_node* LIFO (); //searching for goal state with last in first out strategy
	state_node* FIFO (); //searching for goal state with first in first out strategy
	state_node* heuristic(); // trying to find the soloution better than FIFO :D

	// LIFO is DFS search and FIFO is BFS strategy
};
/////////////////////////////////////////////////////////
void search::action_state(state_node* current_state) 
{
	state_node *next_state;
	cout<<state_list.size()<<endl;
	cout<<"*priest*"<<current_state->priest<< "*killer*"<<current_state->killer<<"***\n";
				if (current_state->boat==1) // this part will do the actins when the boat is on the right side
				{
					if (current_state->priest -2 >= 0 )  //bringing 2 priest to the left
					{
						next_state = new state_node(current_state,current_state->priest -2,current_state->killer,-1);
						if (next_state->priest==0 || next_state->priest >= next_state->killer)
							if (n - next_state->priest == 0 || n - next_state->priest >= n - next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (current_state->killer -2 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest,current_state->killer -2,-1);
						if (next_state->priest==0 || next_state->priest >= next_state->killer)
							if (n - next_state->priest == 0 || n - next_state->priest >= n - next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (current_state->priest -1 >=0 && current_state->killer -1 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest -1,current_state->killer -1,-1);
						if (next_state->priest==0 || next_state->priest >= next_state->killer)
							if (n - next_state->priest == 0 || n - next_state->priest >= n - next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (current_state->priest -1 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest -1,current_state->killer,-1);
						if (next_state->priest==0 || next_state->priest >= next_state->killer)
							if (n - next_state->priest == 0 || n - next_state->priest >= n - next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (current_state->killer -1 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest,current_state->killer-1,-1);
						if (next_state->priest==0 || next_state->priest >= next_state->killer)
							if (n - next_state->priest == 0 || n - next_state->priest >= n - next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
				}
				if (current_state->boat== -1) // this part will do the actins when the boat is on the left side
				{
					if (n - current_state->priest -2 >= 0 ) //bringing 2 priest to the right side
					{
						next_state = new state_node(current_state,current_state->priest +2,current_state->killer, 1);
						if (next_state->priest==0 || next_state->priest >= next_state->killer)
							if (n - next_state->priest == 0 || n - next_state->priest >= n - next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (n - current_state->killer -2 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest,current_state->killer +2, 1);
						if (next_state->priest==0 || next_state->priest >= next_state->killer)
							if (n - next_state->priest == 0 || n - next_state->priest >= n - next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;	
					} 
					if (n - current_state->priest -1 >=0 && n - current_state->killer -1 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest +1,current_state->killer +1, 1);
						if (next_state->priest==0 || next_state->priest >= next_state->killer)
							if (n - next_state->priest == 0 || n - next_state->priest >= n - next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (n - current_state->priest -1 >= 0 )
					{
						next_state = new state_node(current_state,current_state->priest +1,current_state->killer, 1 );
						if (next_state->priest==0 || next_state->priest >= next_state->killer)
							if (n - next_state->priest == 0 || n - next_state->priest >= n - next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
					if (n - current_state->killer -1 >= 0 ) 
					{
						next_state = new state_node(current_state,current_state->priest,current_state->killer+1, 1);
						if (next_state->priest==0 || next_state->priest >= next_state->killer)
							if (n - next_state->priest == 0 || n - next_state->priest >= n - next_state->killer)
						state_list.push_back(next_state);
						else delete next_state;
					}
				}
}
////////////////////////////////////////////////////////
state_node* search::FIFO() //search in tree with first in first out mode
{
	long int count=0;
	state_list.push_back(start_state); // add first state to vector
	while (state_list.size()>0)
	{
			cout<<state_list.size()<<"*********"<<endl;

		count ++;
		state_node *current_state;
		current_state = state_list.front();
		state_list.erase(state_list.begin());
		if ( current_state->priest==0 && current_state->killer==0 )
		{
			cout<<"goal state founded";
			cout<<"***"<<count<<"***";
			//cout<<current_state->parent<<endl;
			goal_state = new state_node;
			goal_state = current_state;
			return current_state;		} 
		else
			action_state(current_state);

	}
}
/////////////////////////////////////////////////////////
state_node* search::heuristic()
{
	
	long int count=0;
	long int i,i_max=0;
	int b_flag=1; //this variable will help us to bring peaple to  and so onleft on time and next tilem bring to right ( in states )
	state_list.push_back(start_state); // add first state to vector
	while (state_list.size()>0)	
	{
		count ++;
		state_node *current_state;
		//while (b_flag != state_list.at(i)->boat)
		//{

		//}
		current_state = state_list.front();
		for (i=0;i<state_list.size();i++)
		{
			//if (b_flag == state_list.at(i)->boat )
		//	{	
				if ( state_list.at(i)->priest + state_list.at(i)->killer < current_state->priest + current_state->killer )
				{
				current_state = state_list.at(i);
				i_max=i;
				}
		//	}
		//	else 
		//		if ( state_list.at(i)->priest + state_list.at(i)->killer < current_state->priest + current_state->killer )
		//		current_state = state_list.at(i);
		}

		state_list.erase(state_list.begin() + i_max );
		


		if ( current_state->priest==0 && current_state->killer==0 )
		{
			cout<<"goal state founded";
			cout<<"***"<<count<<"***";
			goal_state = new state_node;
			goal_state = current_state;
			return current_state;		} 
		else
			action_state(current_state);

	}
}



int main ()
{
	class search *condition;
	int n,flag;
	state_node *ans;
	cout<<"enter the number of killer = priesst = " ;
	cin>>n;
	cout<<"1. heuristic\n2.FIFO: ";
	cin>>flag;
	condition = new search(n);
	if (flag == 1)
		ans = condition->heuristic();
	else
		ans = condition->FIFO();

	cout<<endl<<ans->boat<<"	"<<ans->killer;
	cout<<"salam"<<"\n \n";
	condition->show_the_path_of_goal_state(condition->goal_state);

	return 0;
}
