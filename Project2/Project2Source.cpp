// Andrew Le
// andrewle19@csu.fullerton.edu	
// Project 2

#include <iostream>
#include <string>
#include <iostream>
using namespace std;


class List{
private:
	// node struct
	struct node{
		int number; // story number
		string name; // name of story
		string text; // text in story
		int priority; // Priority 1-5
		int team; // Team number / 0-4
		bool done; // check if done or not
		node *next; // ptr to next node
	};

	node* head; // head of list
	node* current; // the current node
	node* temp; // temp node

public:
	// default constuctor
	List()
	{
		head = NULL;
		current = NULL;
		temp = NULL;
	}

	// Fill the back log with stories
	// objective: Make the list by creating nodes from the back of the list 
	// parameter: story number, story name, story text, prority of story, team number, done or not done bool 
	void FillBacklog(int my_number, string storyname, string storytext, int storypriority, int my_team, bool status){
		node* n = new node; // make new node
		n->next = NULL; // make it point to Null this will put node at the end of the list
		// add data to story
		n->number = my_number;
		n->name = storyname;
		n->text = storytext;
		n->priority = storypriority;
		n->team = my_team;
		n->done = status;


		if (head != NULL) // if the head already exists
		{
			current = head; // make the current ptr point to the head

			while (current->next != NULL) // while we are not at the end
			{
				current = current->next; // the current pointer will point to the next pointer in list

			}

			current->next = n;
		}
		else
		{
			head = n;
		}
	}

	//Add story
	// Objective: add story to the front of the list
	// parameter: story number, story name, story text, prority of story, team number, done or not done
	void AddStory(int my_number, string storyname, string storytext, int storypriority, int my_team, bool status)
	{
		node* n = new node; // make new node
		n->next = head; // make it point to the head of the story

		// add data to story
		n->number = my_number;
		n->name = storyname;
		n->text = storytext;
		n->priority = storypriority;
		n->team = my_team;
		n->done = status;


		current = head; // make the current ptr point to old head
		head = n; // make head point to new node
	}


	// Remove story by story name
	// objective search the back log for a story then delete it basically deleting a node containing the sotry name
	// parameter: story name
	void DeleteStory(string storyname)
	{
		node* deleteptr = NULL; // deletion ptr
		current = head; // current point to head
		temp = head; // temp point to head

		while (current != NULL && current->name != storyname) // loop will not end unless list ends or node is found
		{
			temp = current; // temp will be one step behind current
			current = current->next; // current is on track
		}
		if (current == NULL)// if current pointer is at the end it means the name was not found
		{
			cout << storyname << " was not found in the list" << endl;
		}
		else
		{
			deleteptr = current; // set the delete point to current
			current = current->next; // makes current point to next node
			temp->next = current; // patches the hole created by deleteing the found ptr by pointing to current ptr

			// if the story name is found in the head of the list
			if (deleteptr == head)
			{
				head = head->next; // head will equal the next node
				temp = NULL;
			}
			cout << "The Story " << storyname << " was deleted " << endl;
		}
		delete deleteptr; // delete deleteptr for better memory allocation


	}

	// Find Story 
	// Objective: search story by story name 
	// return found story
	void FindStory(string storyname)
	{
		bool found = false;
		current = head;
		while (found == false && current != NULL)// search entire thing till done
		{
			if (current->name == storyname)
			{

				cout << "Story " << storyname << " found " << endl;
				cout << "Story Number: " << current->number << endl;
				cout << "Story Name: " << current->name << endl;
				cout << "Story Text: " << current->text << endl;
				cout << "Story Priority " << current->priority << endl;
				if (current->team == 0) // if team number is 0 it means there is no team 
				{
					cout << "Story Team: No Team " << endl;
				}
				else
				{
					cout << "Story Team: " << current->team << endl;
				}
				if (current->done == true)
				{
					cout << "Story Status: Done" << endl;
				}
				else
				{
					cout << "Story Status: Not Done" << endl;
				}
				cout << '\n';
				found = true;
			}
			// advance pointer / list
			current = current->next;
		}
		if (found == false)
		{
			cout << "Story " << storyname << " not found" << endl;
		}
	}

	// Find Stories of a given Priority
	// objective: search for stories with given priorty 
	void FindPriorityStory(int priority)
	{
		bool found = false; // if priority of story not found
		current = head; // make current point to the head
		while (current != NULL)
		{
			if (current->priority == priority)
			{
				// display stories with given prioirty
				cout << "Priority: " << priority << endl;
				cout << "Story Number: " << current->number << endl;
				cout << "Story Name: " << current->name << endl;
				cout << "Story Text: " << current->text << endl;
				cout << "Story Priority " << current->priority << endl;
				if (current->team == 0) // if team number is 0 it means there is no team 
				{
					cout << "Story Team: No Team " << endl;
				}
				else
				{
					cout << "Story Team: " << current->team << endl;
				}
				if (current->done == true)
				{
					cout << "Story Status: Done" << endl;
				}
				else
				{
					cout << "Story Status: Not Done" << endl;
				}
				cout << '\n';

				found = true;
			}
			// advance the list and ptr
			current = current->next;
		}
		if (found == false)
		{
			cout << "No Stories for Priority " << priority << endl;
		}
	}

	// Find Team story
	// Find Stories for a given Team by using team number to search for stories
	void FindTeamStory(int team)
	{
		bool found = false; // if priority of story not found
		current = head; // make current point to the head
		while (current != NULL)
		{
			if (current->team == team)
			{
				// display stories with given team
				if (team == 0) // if there is no team
				{
					cout << "Unassigned Team Stories" << endl;
				}
				else
				{
					cout << "Team: " << team << " Stories" << endl;; // if there is a team
				}
				cout << "Story Number: " << current->number << endl;
				cout << "Story Name: " << current->name << endl;
				cout << "Story Text: " << current->text << endl;
				cout << "Story Priority " << current->priority << endl;
				if (current->team == 0) // if team number is 0 it means there is no team 
				{
					cout << "Story Team: No Team " << endl;
				}
				else
				{
					cout << "Story Team: " << current->team << endl;
				}
				if (current->done == true)
				{
					cout << "Story Status: Done" << endl;
				}
				else
				{
					cout << "Story Status: Not Done" << endl;
				}
				cout << '\n';

				found = true;
			}
			// advance the list and ptr
			current = current->next;
		}
		if (found == false)
		{
			cout << "No Stories for Priority " << team << endl;
		}
	}

	// Assign Priority to a story
	// objective: Assign priority to stories by first by searching for a story
	// parameter list: priorty of story, name of story
	void AssignPriority(string name)
	{
		current = head; // current points to head
		bool found = false; // checking if found
		int priority; // priority 
		while (found == false && current != NULL)// search entire thing till done
		{
			if (current->name == name)
			{

				cout << "Assign Priority(1-5) to Story: " << endl;
				cin >> priority;
				current->priority = priority;

				found = true;
			}
			// advance pointer / list
			current = current->next;
		}
		if (found == false)
		{
			cout << "Story " << name << " not found" << endl;
		}
	}

	// Assign Team
	// objective: Assigning a Team to a story by searching through list with stories number
	void AssignTeam(int storynumber)
	{
		current = head; // current will point to head of list
		bool found = false; // check if story number is found
		int assignteam; // assign team if story is found 0-4
		while (current != NULL && found == false)// traverse the list
		{
			if (current->number == storynumber) // if story is found
			{
				cout << "Assign Team to Story(0-5): " << endl;
				cin >> assignteam;
				current->team = assignteam;
				found = true;
			}
			// advance list
			current = current->next;

		}
		if (found == false)
		{
			cout << "Story " << storynumber << " not found " << endl;
		}
	}

	// Assign Done or Not
	// Assign if story is done or not done in backlog by searching through list with story name
	void AssignStatus(string name)
	{
		current = head; // current points to head
		bool found = false; // checking if found
		bool done; // done or not done depending on status
		string status;
		while (found == false && current != NULL)// search entire thing till done
		{
			if (current->name == name)
			{
				bool awnser = false; // check if user choice is valid
				while (awnser == false)
				{
					cout << "Is the Story Done or Not Done?(yes/no): " << endl; // see if story is done or not
					cin >> status;

					if (status == "yes")
					{
						done = true;
						current->done = done;
						awnser = true;
					}
					else if (status == "no")
					{
						done = false;
						current->done = done;
						awnser = true;
					}
					else
					{
						cout << "Not Valid Choice " << endl;
					}

					found = true;
				}
			}
			// advance pointer / list
			current = current->next;
		}
		if (found == false)
		{
			cout << "Story " << name << " not found" << endl;
		}
	}

	// DisplayBacklog Size
	void BacklogSize()
	{
		current = head; // curent pointer will point at head of list
		int counter = 0; // count the size of Backlog
		while (current != NULL) // traverse list until the end
		{
			counter++;
			current = current->next;
		}

		cout << "Size of Backlog is " << counter << " stories" << endl;
	}

	//Order by Priority
	// Show the list ordered by prioirty 

	void OrderList()
	{
		current = head;// curent ppoint to head of list
		temp = head;
		bool sortingdone = false;
		int i = 0;
		while (i < 6)
		{
			if (current->priority == i + 1)
			{

				// display stories with priority 
				cout << "Priority " << i + 1 << endl;
				cout << "Story Number: " << current->number << endl;
				cout << "Story Name: " << current->name << endl;
				cout << "Story Text: " << current->text << endl;
				cout << "Story Priority " << current->priority << endl;
				cout << "Story Team: " << current->team << endl;
				if (current->done == true)
				{
					cout << "Story Status: Done" << endl;
				}
				else
				{
					cout << "Story Status: Not Done" << endl;
				}
				cout << '\n';
			}
			current = current->next;// advance list
			if (current == NULL) // when current gets to the end of the list 
			{
				current = head; // move back to the front
				i++;
			}
		}

	}

	// Order List by team
	// Show list ordered by team
	void OrderListTeam()
	{

		current = head;// curent ppoint to head of list
		temp = head;
		int i = 0;
		while (i < 5)
		{
			if (current->team == i)
			{

				// display stories with team
				if (current->team == 0)
				{
					cout << "Unassigned Team Stories" << endl;
				}
				else
				{
					cout << "Team" << i + 1 << endl;
				}
				cout << "Story Number: " << current->number << endl;
				cout << "Story Name: " << current->name << endl;
				cout << "Story Text: " << current->text << endl;
				cout << "Story Priority " << current->priority << endl;
				cout << "Story Team: " << current->team << endl;
				if (current->done == true)
				{
					cout << "Story Status: Done" << endl;
				}
				else
				{
					cout << "Story Status: Not Done" << endl;
				}
				cout << '\n';
			}
			current = current->next;// advance list
			if (current == NULL) // when current gets to the end of the list 
			{
				current = head; // move back to the front
				i++;
			}
		}
	}
	// Add or Remove first story from backlog
	void AddorRemoveFirst()
	{
		current = head; // make current point to head
		int choice; // user choice to remove story or keep it

		cout << "First Story" << endl;
		cout << "Story Number: " << current->number << endl;
		cout << "Story Name: " << current->name << endl;
		cout << "Story Text: " << current->text << endl;
		cout << "Story Priority " << current->priority << endl;
		if (current->team == 0) // if team number is 0 it means there is no team 
		{
			cout << "Story Team: No Team " << endl;
		}
		else
		{
			cout << "Story Team: " << current->team << endl;
		}
		if (current->done == true)
		{
			cout << "Story Status: Done" << endl;
		}
		else
		{
			cout << "Story Status: Not Done" << endl;
		}
		cout << '\n';

		bool awnser = false; // check if user choice is valid
		while (awnser == false)
		{
			cout << "Would you like to Add or Remove First Story: " << endl; // see if story is done or not
			cout << "1: Add Story" << endl;
			cout << "2: Remove First Story" << endl;
			cin >> choice;

			// Add Story
			if (choice == 1)
			{
				int storynumber; // stores user input story number
				string name; // stores story name
				string text; // story text
				int priority; // story priority
				int team; // team number
				bool done; // story is done or not done depending on status

				string status; // done or not done;
				cout << "Enter Story Number: " << endl; // grab story number
				cin >> storynumber;
				cout << "Enter Story Name: " << endl; // grab story Name;
				cin >> name;
				cout << "Enter Story Text: " << endl; // grab story text
				cin.ignore(); // buffer bewtween
				getline(cin, text);
				cout << "Enter Story Priority(1-5): " << endl; // grab story Priority
				cin >> priority;
				cout << "Enter Story Team Number(0-4): " << endl; // grab story team number
				cin >> team;

				bool awnser2 = false; // check if user choice is valid
				while (awnser2 == false)
				{
					cout << "Is the Story Done or Not Done?(yes/no): " << endl; // see if story is done or not
					cin >> status;

					if (status == "yes")
					{
						done = true;
						awnser2 = true;
					}
					else if (status == "no")
					{
						done = false;
						awnser2 = true;
					}
					else
					{
						cout << "Not Valid Choice " << endl;
					}
				}
				
				AddStory(storynumber, name, text, priority, team, done);
				DisplayList();
				awnser = true;
			
			}
			else if (choice == 2)
			{
				temp = current;
				current = NULL;
				head = temp->next;
				awnser = true;
			}
			else
			{
				cout << "Not Valid Choice " << endl;
			}


		}
	}

	// Add or Remove first story from backlog
	void AddorRemoveLast()
	{
		current = head; // make current point to head
		temp = head;
		node* deleteptr = NULL;
		bool awnser = false;
		int choice; // user choice
		while (awnser == false)
		{
			if (current->next == NULL) // finds last story
			{

				cout << "Last Story" << endl;
				cout << "Story Number: " << current->number << endl;
				cout << "Story Name: " << current->name << endl;
				cout << "Story Text: " << current->text << endl;
				cout << "Story Priority " << current->priority << endl;
				if (current->team == 0) // if team number is 0 it means there is no team 
				{
					cout << "Story Team: No Team " << endl;
				}
				else
				{
					cout << "Story Team: " << current->team << endl;
				}
				if (current->done == true)
				{
					cout << "Story Status: Done" << endl;
				}
				else
				{
					cout << "Story Status: Not Done" << endl;
				}
				cout << '\n';

					cout << "Would you like to Add or Remove Last Story?:" << endl;
					cout << "1: Add" << endl;
					cout << "2: Remove" << endl;
					cin >> choice;
					if (choice == 2)
					{
						current = NULL;// delete the last story
						temp->next = NULL;
						DisplayList();
						awnser = true;
					}
					else if (choice == 1)
					{
						int storynumber; // stores user input story number
						string name; // stores story name
						string text; // story text
						int priority; // story priority
						int team; // team number
						bool done; // story is done or not done depending on status

						string status; // done or not done;
						cout << "Enter Story Number: " << endl; // grab story number
						cin >> storynumber;
						cout << "Enter Story Name: " << endl; // grab story Name;
						cin >> name;
						cout << "Enter Story Text: " << endl; // grab story text
						cin.ignore(); // buffer bewtween
						getline(cin, text);
						cout << "Enter Story Priority(1-5): " << endl; // grab story Priority
						cin >> priority;
						cout << "Enter Story Team Number(0-4): " << endl; // grab story team number
						cin >> team;

						bool awnser2 = false; // check if user choice is valid
						while (awnser2 == false)
						{
							cout << "Is the Story Done or Not Done?(yes/no): " << endl; // see if story is done or not
							cin >> status;

							if (status == "yes")
							{
								done = true;
								awnser2 = true;
							}
							else if (status == "no")
							{
								done = false;
								awnser2 = true;
							}
							else
							{
								cout << "Not Valid Choice " << endl;
							}
						}
						FillBacklog(storynumber, name, text, priority, team, done);
						DisplayList();
						awnser = true;
					}
					else
					{
						cout << "Not Valid Choice " << endl;
					}
				
			}
			temp = current;
			current = current->next;
		}
	}

	// Change Data in the story
	// parameter list: search name in all stories to see if it is in there
	void ChangData(string name)
	{
		current = head; // current points to head
		bool found = false; // checking if found
		bool done; // done or not done depending on status
		string status; // to change the done or not done data
		int number; // to change the story number
		string storyname; // to change the story name
		int teamnumber; // change the team number
		string text; // change story text
		int choice; // what the user wants to change
		while (found == false && current != NULL)// search entire thing till done
		{
			if (current->name == name)
			{
				bool awnser = false; // check if user choice is valid
				while (awnser == false)
				{
					// Display found Story first
					cout << "Story Number: " << current->number << endl;
					cout << "Story Name: " << current->name << endl;
					cout << "Story Text: " << current->text << endl;
					cout << "Story Priority " << current->priority << endl;
					if (current->team == 0) // if team number is 0 it means there is no team 
					{
						cout << "Story Team: No Team " << endl;
					}
					else
					{
						cout << "Story Team: " << current->team << endl;
					}
					if (current->done == true)
					{
						cout << "Story Status: Done" << endl;
					}
					else
					{
						cout << "Story Status: Not Done" << endl;
					}
					cout << '\n';

					cout << "What Data would you like to change?" << endl;
					cout << "1: Story Number " << endl;
					cout << "2: Story Name " << endl;
					cout << "3: Story Text " << endl;
					cout << "4: Story Team Number" << endl;
					cout << "5: Story Done or Not" << endl;
					cin >> choice; // user chooses what he wants to change

					string repeat; // if the user wants to change something else right after

					// change the story number
					if (choice == 1)
					{
						cout << "Enter Story number" << endl;
						cin >> number;
						current->number = number;
						awnser = true;
					}

					// Change the Story name
					if (choice == 2)
					{
						cout << "Enter Story Name" << endl;
						cin >> name;
						current->name = name;
						awnser = true;
					}

					// Change the Story Text
					if (choice == 3)
					{
						cout << "Enter Story Text" << endl;
						cin.ignore();
						getline(cin, text);
						current->text = text;
						awnser = true;
					}
					// Change the Team Number
					if (choice == 4)
					{
						cout << "Enter Team Number(0-4): " << endl;
						cin >> teamnumber;
						current->team = teamnumber;
						awnser = true;
					}

					// done or not done
					if (choice == 5)
					{
						bool validchoice = false; // check if choice is valid

						while (validchoice == false)
						{
							cout << "Is the Story Done or Not Done?(yes/no): " << endl; // see if story is done or not
							cin >> status;
							if (status == "yes")
							{
								done = true;
								current->done = done;
								validchoice = true;
								awnser = true;
							}
							else if (status == "no")
							{
								done = false;
								current->done = done;
								validchoice = true;
								awnser = true;
							}
							else
							{
								cout << "Not Valid Choice " << endl;
							}
						}
					}
					if (choice > 5 || choice < 0)
					{
						cout << "Invaid choice " << endl;
					}

				}
				cout << "Story Number: " << current->number << endl;
				cout << "Story Name: " << current->name << endl;
				cout << "Story Text: " << current->text << endl;
				cout << "Story Priority " << current->priority << endl;
				if (current->team == 0) // if team number is 0 it means there is no team 
				{
					cout << "Story Team: No Team " << endl;
				}
				else
				{
					cout << "Story Team: " << current->team << endl;
				}
				if (current->done == true)
				{
					cout << "Story Status: Done" << endl;
				}
				else
				{
					cout << "Story Status: Not Done" << endl;
				}
				cout << '\n';
				found = true;
			}
			// advance pointer / list
			current = current->next;
		}
		if (found == false)
		{
			cout << "Story " << name << " not found" << endl;
		}
	}


	// Display Done then Not done stories
	void DisplayDoneorNotDone()
	{
		current = head; // current points to head
		cout << "Completed Stories " << endl; // printed out completed stories

		while (current != NULL)
		{
			if (current->done == true)
			{
				cout << "Story Number: " << current->number << endl;
				cout << "Story Name: " << current->name << endl;
				cout << "Story Text: " << current->text << endl;
				cout << "Story Priority " << current->priority << endl;
				if (current->team == 0) // if team number is 0 it means there is no team 
				{
					cout << "Story Team: No Team " << endl;
				}
				else
				{
					cout << "Story Team: " << current->team << endl;
				}
				if (current->done == true)
				{
					cout << "Story Status: Done" << endl;
				}
				else
				{
					cout << "Story Status: Not Done" << endl;
				}
				cout << '\n';
				current = current->next;
			}
			current = current->next;

		}
		current = head;
		cout << "Unfinished Stories" << endl;
		while (current != NULL)
		{
			if (current->done == false)
			{
				cout << "Story Number: " << current->number << endl;
				cout << "Story Name: " << current->name << endl;
				cout << "Story Text: " << current->text << endl;
				cout << "Story Priority " << current->priority << endl;
				if (current->team == 0) // if team number is 0 it means there is no team 
				{
					cout << "Story Team: No Team " << endl;
				}
				else
				{
					cout << "Story Team: " << current->team << endl;
				}
				if (current->done == true)
				{
					cout << "Story Status: Done" << endl;
				}
				else
				{
					cout << "Story Status: Not Done" << endl;
				}
				cout << '\n';
			}
			current = current->next;
		}

	}

	// Display the contents of the list
	void DisplayList(){
		// current will start from the beggining of the list
		current = head;

		// the current pointer
		while (current != NULL)
		{
			cout << "Story Number: " << current->number << endl;
			cout << "Story Name: " << current->name << endl;
			cout << "Story Text: " << current->text << endl;
			cout << "Story Priority " << current->priority << endl;
			if (current->team == 0) // if team number is 0 it means there is no team 
			{
				cout << "Story Team: No Team " << endl;
			}
			else
			{
				cout << "Story Team: " << current->team << endl;
			}
			if (current->done == true)
			{
				cout << "Story Status: Done" << endl;
			}
			else
			{
				cout << "Story Status: Not Done" << endl;
			}
			cout << '\n';
			current = current->next;
		}
	}

	// Team Done
	// Display if any teams are done
	void TeamDone()
	{

		current = head;// curent ppoint to head of list
		temp = head;
		// Check if each team is done
		bool teamdone1 = true;
		bool teamdone2 = true;
		bool teamdone3 = true;
		bool teamdone4 = true;
		int i = 0;
		while (current->next != NULL) // Traverse the list to the end
		{
			if (current->team == 1) // if the story is in team 1
			{
				if (current->done == false) // if a story is found false stories have not completed
				{
					teamdone1 = false;
				}
			}
			if (current->team == 2) // if the story is in team 2
			{
				if (current->done == false)// if a story is found false stories have not completed
				{
					teamdone2 = false;
				}
			}
			if (current->team == 3) // if the story is in team 3
			{
				if (current->done == false)// if a story is found false stories have not completed
				{
					teamdone3 = false; 
				}
			}
			if (current->team == 4) // if the story is in team 4
			{
				if (current->done == false)// if a story is found false stories have not completed
				{
					teamdone4 = false;
				}
			}
			current = current->next;// advance list
		}

		if (teamdone1 == false)
		{
			cout << "Team 1 has not finished all stories" << endl;
		}
		else
		{
			cout << "Team 1 has finished all stories" << endl;
		}
		if (teamdone2 == false)
		{
			cout << "Team 2 has not finished all stories" << endl;
		}
		else
		{
			cout << "Team 2 has finished all stories" << endl;
		}
		if (teamdone3 == false)
		{
			cout << "Team 3 has not finished all stories" << endl;
		}
		else
		{
			cout << "Team 3 has finished all stories" << endl;
		}
		if (teamdone4 == false)
		{
			cout << "Team 4 has not finished all stories" << endl;
		}
		else
		{
			cout << "Team 4 has finished all stories" << endl;
		}
	}

};


int main()
{
	List Backlog;
	bool choice = true;

	// Menu 
	while (choice == true)
	{
		int userchoice; // user choose option
		cout << "Story Backlog " << endl;
		cout << "0: Exit" << endl;
		cout << "1: Fill The Backlog" << endl;
		cout << "2: Add Story to Front of the list" << endl;
		cout << "3: Display Backlog " << endl;
		cout << "4: Delete Story " << endl;
		cout << "5: Find Story by Story Name " << endl;
		cout << "6: Find Stories by Priority " << endl;
		cout << "7: Find Stories of Given Team" << endl;
		cout << "8: Assign Priority " << endl;
		cout << "9: Assign Team " << endl;
		cout << "10: Done or Not Done " << endl;
		cout << "11: Order Stories by Priority " << endl;
		cout << "12: Order Stories by Team " << endl;
		cout << "13: Add or Remove First Story " << endl;
		cout << "14: Add or Remove Last Story " << endl;
		cout << "15: Display The Finished Stories then Unfinished Stories" << endl;
		cout << "16: Display Size of The Backlog " << endl;
		cout << "17: Change Data in a Story in List" << endl;
		cout << "18: Check if Any Team is Finished " << endl;
		cout << "19: Input Sample Test Data " << endl; // this puts in test data for the user to test the functions
		cin >> userchoice;
		cout << '\n';

		// Exit Program
		if (userchoice == 0)
		{
			cout << "Exiting Program " << endl;
			choice = false;
		}

		// Fill the Backlog(Make the list)
		if (userchoice == 1)
		{
			bool Repeat; // this will make function repeat to add more nodes
			string choice; // takes user choice
			int storynumber; // stores user input story number
			string name; // stores story name
			string text; // story text
			int priority; // story priority
			int team; // team number
			bool done; // done or not done?

			do
			{
				string status; // done or not done?
				cout << "Enter Story Number: " << endl; // grab story number
				cin >> storynumber;
				cout << "Enter Story Name: " << endl; // grab story Name;
				cin >> name;
				cout << "Enter Story Text: " << endl; // grab story text
				cin.ignore(); // buffer bewtween
				getline(cin, text);
				cout << "Enter Story Priority(1-5): " << endl; // grab story Priority
				cin >> priority;
				cout << "Enter Story Team Number(0-4): " << endl; // grab story team number
				cin >> team;

				// to check if done or not done
				bool awnser = false; // check if user choice is valid
				while (awnser == false)
				{
					cout << "Is the Story Done or Not Done?(yes/no): " << endl; // see if story is done or not
					cin >> status;

					if (status == "yes")
					{
						done = true;
						awnser = true;
					}
					else if (status == "no")
					{
						done = false;
						awnser = true;
					}
					else
					{
						cout << "Not Valid Choice " << endl;
					}


				}


				// fill backlog create first node
				Backlog.FillBacklog(storynumber, name, text, priority, team, done);

				bool valid = false; // check if user choice is valid
				// if user wants to add another node 
				while (valid == false) // check if user input
				{
					cout << "Would you like to add another story(yes/no) " << endl;
					cin >> choice;
					if (choice == "yes")
					{
						Repeat = true; // means will loop again creating new node
						valid = true;
					}
					else if (choice == "no")
					{
						Repeat = false; // will not loop again
						valid = true;
					}
					else
					{
						valid = false; // the awnser choice was not valid go again
						cout << "Choice not valid " << endl;
					}
				}
			} while (Repeat == true);
			cout << '\n';
		}

		// Add story to the front of the list
		if (userchoice == 2)
		{
			int storynumber; // stores user input story number
			string name; // stores story name
			string text; // story text
			int priority; // story priority
			int team; // team number
			bool done; // story is done or not done depending on status

			string status; // done or not done;
			cout << "Enter Story Number: " << endl; // grab story number
			cin >> storynumber;
			cout << "Enter Story Name: " << endl; // grab story Name;
			cin >> name;
			cout << "Enter Story Text: " << endl; // grab story text
			cin.ignore(); // buffer bewtween
			getline(cin, text);
			cout << "Enter Story Priority(1-5): " << endl; // grab story Priority
			cin >> priority;
			cout << "Enter Story Team Number(0-4): " << endl; // grab story team number
			cin >> team;

			bool awnser = false; // check if user choice is valid
			while (awnser == false)
			{
				cout << "Is the Story Done or Not Done?(yes/no): " << endl; // see if story is done or not
				cin >> status;

				if (status == "yes")
				{
					done = true;
					awnser = true;
				}
				else if (status == "no")
				{
					done = false;
					awnser = true;
				}
				else
				{
					cout << "Not Valid Choice " << endl;
				}
			}
			Backlog.AddStory(storynumber, name, text, priority, team, done);

		}


		// Display List
		if (userchoice == 3)
		{
			cout << "Story Backlog" << endl;
			Backlog.DisplayList();
		}

		// delete story
		if (userchoice == 4)
		{
			string deletestory; // name story to delete
			cout << "Enter the Story name of the story you want to delete: " << endl;
			cin >> deletestory;

			Backlog.DeleteStory(deletestory);
			cout << "\n";

		}

		// find story
		if (userchoice == 5)
		{

			string name; // search through story name
			cout << "Enter the Story name you want to search " << endl;
			cin >> name;
			cout << "\n";
			Backlog.FindStory(name);
			cout << '\n';
		}

		// find story by priority 
		if (userchoice == 6)
		{
			int priority; // search through priority 
			cout << "Enter priority number " << endl;
			cin >> priority;

			Backlog.FindPriorityStory(priority);
			cout << '\n';
		}

		// find stories by given team
		if (userchoice == 7)
		{
			int team; // search through list for team 
			cout << "Enter Team Number(0-4) " << endl;
			cin >> team;

			Backlog.FindTeamStory(team);
			cout << '\n';
		}

		// Assign Priority to Story
		if (userchoice == 8)
		{
			string name; // search through story name
			cout << "Enter the Story Name to Search " << endl;
			cin >> name;

			Backlog.AssignPriority(name);
			cout << '\n';
		}

		// Assign team to story
		if (userchoice == 9)
		{
			int storynumber; // search through story number
			cout << "Enter the Story number: " << endl;
			cin >> storynumber;

			Backlog.AssignTeam(storynumber);
			cout << '\n';
		}

		// Assign Done or Not
		if (userchoice == 10)
		{
			string name; // search through story name
			cout << "Enter the Story name to Search " << endl;
			cin >> name;

			Backlog.AssignStatus(name);
			cout << '\n';
		}

		// Order list by priority then team
		if (userchoice == 11)
		{
			Backlog.OrderList();
		}

		// Order list by Team
		if (userchoice == 12)
		{
			Backlog.OrderListTeam();
		}

		// Add or Remove First Story
		if (userchoice == 13)
		{
			Backlog.AddorRemoveFirst();

		}

		// Add or Remove Last Story
		if (userchoice == 14)
		{
			Backlog.AddorRemoveLast();
		}

		// Display the finished stories then the unfinished ones
		if (userchoice == 15)
		{
			Backlog.DisplayDoneorNotDone();
		}


		// backlog size
		if (userchoice == 16)
		{
			Backlog.BacklogSize();
			cout << '\n';
		}

		// Change data in story in list
		if (userchoice == 17)
		{
			string name; // search through story name
			cout << "Enter the Story name to Search " << endl;
			cin >> name;

			Backlog.ChangData(name);
			cout << '\n';
		}

		// Team Done?
		if (userchoice == 18)
		{
			Backlog.TeamDone();
			cout << '\n';
		}

		//Input Sample test data 
		if (userchoice == 19)
		{
			Backlog.FillBacklog(1, "FillStoryBacklog", "Insert set of stories in Story Backlog", 2, 1, true);
			Backlog.FillBacklog(2, "PrintOutData", "Traverse the list print out the data", 4, 2, false);
			Backlog.FillBacklog(3, "AddStory", "Someone on team adds single story to Backlog", 3, 3, true);
			Backlog.FillBacklog(4, "RemoveStory", "A Story is deleted in Backlog", 1, 4, false);
			Backlog.FillBacklog(5, "FindStory", "Find the Story in the List", 1, 0, false);
			Backlog.FillBacklog(6, "AssignPriority", "Assign the priority to certain story", 5, 2, false);
			cout << "Sample Test Data Applied " << endl;
			cout << '\n';
		}
	}
	system("pause");
	return 0;
}