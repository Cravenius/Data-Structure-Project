#include <iostream>
#include <conio.h>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
#include <windows.h>
#include <chrono>
#include <Mmsystem.h>
#include <mciapi.h>
#include <fstream>
#include <stdio.h>
#include <string>
#define lvl 5
#define row 20
#define col 63
#define bomb_count 3
#pragma comment(lib, "Winmm.lib")
#pragma warning(disable:4996)

using namespace std;
using namespace std::chrono;

char map1[row][col] = {
	"+------------------------------------------------------------+",
	"|             #      #    # #   #      #    #       #        |",
	"| ## #  # #  #   #  #   #     #    #      #   #   #   #      |",
	"|   # ###  ###  #  #  #    #    #    #          #   #    ### |",
	"| #            #       #   ###  ## #   #  #  #         #     |",
	"| ###### # ##########   #     #             ###   #### #   ##|",
	"|   #    #     #  #        #  ######    #    # #    #        |",
	"| ### ###########       #      #    #  #  #       ### ###### |",
	"|             ####  #    #  #    #    #  #   #  #    ##      |",
	"| ###  #######     # #    #  ##   #  #   #    ##  #  ### ####|",
	"| #           # ### ###  ##   # #        #     #             |",
	"| #  # ######## # # ######## ############################### |",
	"| # ##        #        #   #    #  #   #                     |",
	"| #  ### ###  # ###    #  #   #   ##      ###################|",
	"| #  #  #  #   #       #   #  #  # #  #  #  #   ##  #     #  |",
	"|  #  #  #  #   #      #  #  #     ###      #      #   #     |",
	"|  #  #  #  ### #    ###      #   ##    #  ## ##       #   # |",
	"|  #  #       #  #       ##    #   #  #           # #        |",
	"|     # ### #    #   ####    #        #   ###     #   #   #  |",
	"+------------------------------------------------------------+"
};

char map2[row][col] = {
	"+------------------------------------------------------------+",
	"|     #           #                 ### # ###################|",
	"| # ####  #####    ##  ###    #####         ###            ##|",
	"|   #  #      ###                    ###  ###   ###### ###   |",
	"|    #######  #       #######  #########       ######  ######|",
	"| #          ###  #####        ###      ###         #  #     |",
	"|   #######         ##    ###   ####        ####    #  # ### |",
	"|     ######### # #####    ##########  ###    ###   #        |",
	"|    #                           ###     ###        #  ##### |",
	"|    #   ############    ####                 ####  ###    # |",
	"|    #   #     #  ###          ###########          ##     # |",
	"|       ##  #  #           ###                  #####      # |",
	"|    #  ##         ######           #####     ###       #### |",
	"|    #    ######   #      #########                 #####  # |",
	"|#######  #######  #             #####           ###    ##   |",
	"|           ###    #  ##########  #    ####   ###     ###  # |",
	"| ## ######  # ##      ########   #        ###  #  # #       |",
	"|  #      #     ##  ###   ###     #  ###  ####    ##    ## ##|",
	"| ######  # ######  #   ####        ##          ###  #####   |",
	"+------------------------------------------------------------+"
};

char map3[row][col] = {
	"+------------------------------------------------------------+",
	"|   #   #   #   #             #    #     #   #   #  #  #   # |",
	"| #   #   #   #     #   #     #  #     #   #   #  #  #   #   |",
	"| ###############   #   #        #  ## ########              |",
	"|   #     #     #     # #     # ######  #     #   # ######## |",
	"| ###### # ##########   #     #             # #    ### #   ##|",
	"|   #    #     #  #     #  #  ######    #    # #    #        |",
	"| ###############       #    # #    #  #  #       ### ###### |",
	"|             ##### #    #  # #  #    #  #   #  #    ##      |",
	"| # #  #######     # #    #  ##   #  #   #    ##  #  ### ####|",
	"| #  #        # ##  ###  ##   # #        #     #             |",
	"| #  ######## # # # #### ### ##### ######################### |",
	"| #           #        #   #    #  #   #                     |",
	"| #  # # ###### ###    #  #   #   ##      ###################|",
	"| #  #  #  #   #       #   #  #  # #  #  #  #   ##  #     #  |",
	"|  #  #  #  # # #      #  #  #     ###      #      #   #     |",
	"|  #  #  #  ### #    ###      #  # #    #  ## ##       #   # |",
	"|  #  #          #       ##    #  ## #            # #        |",
	"|    #  ###      #   ####    #     #  #   ###     #   #   #  |",
	"+------------------------------------------------------------+"
};

char map4[row][col] = {
	"+------------------------------------------------------------+",
	"| ###########################################################|",
	"|        #     #               #             #  ######  ###  |",
	"| ###### ##### ####            #  ########## #            #  |",
	"|        #     #          ######  #   #  ##  ########     #  |",
	"| ###### # #########      #       #   #     #    ### #   ### |",
	"|   #    #     #  #       #  ######   #   #  #    #         #|",
	"| ###### # ######         #  #        #   #  ### ###### #### |",
	"|   #          ##### #    #  #        #   #   #    ##       #|",
	"| ###  #######     # #    #  #        ###  ##  #  ### ##### #|",
	"|   #        # ### ########                 #             # #|",
	"|   ########## # # ###    # ##### #####                 ### #|",
	"|  ####      #                 #    ########             #  #|",
	"|   ### ###### ###  #      ### #     ###     ########### #   |",
	"| #  #  #  #   #    #  #  #  # #      #  ###         ##  # # |",
	"|    #  #  # # #  # #     # ## #      #        ###    #  # # |",
	"|    #  #  ### #  # ##### #    #      #  ###  # #    #   # # |",
	"|           #  #     #### #  # # #    #                # # # |",
	"|                                         #### ## ######     |",
	"+------------------------------------------------------------+"
};

char map5[row][col] = {
	"+------------------------------------------------------------+",
	"| ##############                   ##############            |",
	"|        #     #               #             #  ######  ###  |",
	"|#####                                          ###########  |",
	"|        #     #          ######                 ########   #|",
	"|####### # #########      #       #   #     #    ###         |",
	"|   #    #     #  #       #  ######   #   #  #    #      #   |",
	"|                                #  #        #   #  ### #### |",
	"|   #          ##### #    #  #   #   #   #    ##       #     |",
	"|####  #######     # #    #  #        ###  ##  #  ###        |",
	"|   #        # ### ########                 #         # #    |",
	"|   #                                           #######      |",
	"|  ####      #                 #    ########         #  #    |",
	"|                         ### # ## ## ### # ### # ######     |",
	"| #  #  #  #   #    #  #  #  # #      #  ###       ##  # #   |",
	"|    #  #  # # #  # #     # ## #      #      ###    #  # #   |",
	"|    #  #  ### #  # ##### #    #      #  ###  # #    #       |",
	"|      #  #     #### #  # # #    #         #      # # #      |",
	"|  ########### ###    ### # # ####        #### #             |",
	"+------------------------------------------------------------+"
};

class MusicPlaylist { // Circular Double Linked List
private:

	class Song {
	public:
		string title;
		Song* prev, * next;
		Song(string title = "") : title(title), prev(NULL), next(NULL) {}
	};

	Song* head, * tail, *current;
	string returnData;
	bool play, repeat;
	const string info = " type mpegvideo alias mp3";
	int count, curr_vl;

	void ChangeMode() {
		if (repeat) {
			mciSendString(s2ws("play mp3 repeat").c_str(), NULL, 0, 0);
		}
		else {
			mciSendString(s2ws("play mp3").c_str(), NULL, 0, 0);
		}
		Volume(curr_vl);
	}

	void PrepareSong() {
		mciSendString(s2ws("close mp3").c_str(), NULL, 0, 0);
		string command = "open ";
		command.append(CurrentSong());
		command.append(info);
		mciSendString(s2ws(command).c_str(), NULL, 0, 0);
	}

	wstring s2ws(const string& s) {
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
		wstring r(buf);
		delete[] buf;
		return r;
	}
public:
	MusicPlaylist() : head(NULL), tail (NULL), current(NULL), play(false), repeat(true), count(0), curr_vl(400) {

		ifstream ifs("Songs.txt");

		if (ifs.is_open()) {
			while (!ifs.eof()) {
				string reader;
				getline(ifs, reader);
				AddSongLast(reader);
				reader.clear();
			}
		}
		ifs.close();
		//Shuffle();
		PrepareSong();
		Play();
	}

	~MusicPlaylist() {
		// no bug found
		while (count > 0) {
			//cout << "Remove " << tail->title << " from song list!\n";
			//cout << "Remove " << head->title << " from song list!\n";
			//RemoveSongLast();
			RemoveSongFront();
		}
	}

	// Add song and Remove song is O(1), which is very fast
	void AddSongLast(string songname) {
		if (head == NULL || tail == NULL) { head = new Song(songname); tail = current = head; } // 0 song
		else {
			Song* node = new Song(songname);
			tail->next = node; 
			node->prev = tail;
			tail = tail->next;
			tail->next = head; // making circular linked list
			node = NULL;
		}
		++count;
	}

	void AddSongFront(string songname) {
		if (head == NULL || tail == NULL) { head = new Song(songname); tail = current = head; } // 0 song
		else {
			Song* node = new Song(songname);
			head->prev = node;
			node->next = head;
			head = head->prev;
			head->prev = tail; // making circular linked list
			node = NULL;
		}
		++count;
	}

	void RemoveSongLast() {
		if (count > 0) {
			if (count == 1) {
				tail = current = NULL;
				delete head;
			}
			else {
				Song* node = tail;
				tail = tail->prev;
				tail->next = head;
				node->next = NULL;
				node->prev = NULL;
				delete node;
			}
			--count;
		}
	}

	void RemoveSongFront() {
		if (count > 0) {
			if (count == 1) {
				head = current = NULL;
				delete tail;
			}
			else {
				Song* node = head;
				head = head->next;
				head->prev = tail;
				node->next = NULL;
				node->prev = NULL;
				delete node;
			}
			--count;
		}
	}

	string CurrentSong() { return current->title; } // get file name of current song

	void Print() { // status print
		cout << "Status: \n";
		if (play) cout << "-) Song " << CurrentSong() << " is being played right now.\n";
		else cout << "-) The song is paused.\n";

		if (repeat) cout << "-) Repeat mode enabled.\n";
		else cout << "-) Repeat mode disabled.\n";

		cout << "-) Current Volume: " << curr_vl / 10 << "%\n";

		cout << "\nSong Playlist (" << count << " songs found): \n";
		Song* traversal = head; int i = 0;
		while (traversal != tail) {
			cout << "#" << ++i << ": " << traversal->title << endl;
			traversal = traversal->next;
		}
		cout << "#" << ++i << ": " << traversal->title << endl;
	}

	void Pause() {
		if (!play) return;
		play = false;
		mciSendString(s2ws("pause mp3").c_str(), NULL, 0, 0);
	}

	void Play() {
		if (play) return;
		play = true;
		ChangeMode();
	}

	void NextSong() {
		if (count < 1) return; // if 0 or 1 song found just skip this process
		if (!play) play = true;
		if (current == tail) current = head;
		else current = current->next;
		PrepareSong();
		ChangeMode();
	}

	void PreviousSong() {
		if (count < 1) return; // if 0 or 1 song found just skip this process
		if (!play) play = true;
		if (current == head) current = tail;
		else current = current->prev;
		PrepareSong();
		ChangeMode();
	}

	void Repeat() {
		if (repeat) {
			repeat = false;
		}
		else {
			repeat = true;
		}
	}

	void PlayRandom() {
		play = false;
		srand((unsigned)time(NULL));
		int random = rand() % count;
		random =  random + log10(pow(random, 2));
		for (int i = 0; i < random; ++i) current = current->next;
		PrepareSong();
		Play();
	}

	void PlaySpecific(string songname) {
		play = false;
		bool found = false;

		for (int i = 0; i < count; ++i) {
			if (CurrentSong() != songname) { 
				current = current->next;
			}
			else {
				found = true;
				break;
			}
		}

		if (found) {
			PrepareSong();
			Play();
		}
		else {
			cout << "Song is not found!! maybe input had wrong format (must include \" character)\n";
			system("pause");
		}
	}

	bool isPlay() { return play; }

	void Shuffle() {
		srand((unsigned)time(NULL));

		if (play) play = false;

		vector <string> v;
		Song* node = head;

		while (node != tail) {
			v.push_back(node->title);
			node = node->next;
		}

		v.push_back(node->title);

		for (int i = 0; i < v.size(); ++i)
			swap(v[i], v[rand() % v.size()]);

		node = head;

		for (int i = 0; i < v.size(); ++i) {
			node->title = v[i];
			node = node->next;
		}

		v.clear();

		PrepareSong();
		Play();
	}

	void Volume(int volume) {
		if (volume >= 0 && volume <= 1000 && play){
			curr_vl = volume;
			string vl = "setaudio mp3 volume to "; vl.append(to_string(curr_vl));
			mciSendString(s2ws(vl).c_str(), NULL, 0, 0);
		}
	}
};

double elapsedTime;

MusicPlaylist playlist;
vector <pair <int, int>> ll;

void gotoxy(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}

class Timer {
private:
	time_point<system_clock> m_StartTime;
	time_point<system_clock> m_EndTime;
	bool m_bRunning = false;
public:
	void start() {
		m_StartTime = system_clock::now();
		m_bRunning = true;
	}

	void stop() {
		m_EndTime = system_clock::now();
		m_bRunning = false;
	}

	double elapsedMilliseconds() {
		time_point<system_clock> endTime;
		if (m_bRunning) endTime = system_clock::now();
		else endTime = m_EndTime;
		return static_cast<double>(duration_cast<milliseconds>(endTime - m_StartTime).count());
	}

	double elapsedSeconds() {
		return elapsedMilliseconds() / 1000.0;
	}
};

Timer timer;

class MapQueueList {
private:

	class MapData {
	public:
		char** map; // data
		int id, minTime;
		MapData* next; // pointer next
		MapData(char maps[row][col], int min, int id) : minTime(min), id(id), next(NULL) {
			this->map = new char* [row];
			for (int i = 0; i < row; ++i) this->map[i] = new char[col];

			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					this->map[i][j] = maps[i][j];
				}
			}
		}

		~MapData() {
			for (int i = 0; i < row; ++i) delete[]this->map[i];
			delete[]this->map;
		}
	};

	int level;
	MapData* head, * tail;
	queue <MapData*> queue;

public:
	MapQueueList() : level(lvl), head(NULL), tail(NULL) {
		this->addLast(new MapData(map1, 25, 1));
		this->addLast(new MapData(map2, 35, 2));
		this->addLast(new MapData(map3, 40, 3));
		this->addLast(new MapData(map4, 20, 4));
		this->addLast(new MapData(map5, 30, 5));
	}

	~MapQueueList() {
		for (int i = 0; i < this->level; ++i) {
			this->removeFront();
		}
		level = 0;

		while (!queue.empty()) {
			delete queue.front();
			queue.pop();
		}
	}

	void addLast(MapData* value) {
		if (!head) {
			head = value;
			tail = head;
		}
		else {
			tail->next = value;
			tail = value;
		}
		++level;
	}

	void removeFront() {
		if (!head) return;
		MapData* temp = this->head;
		this->head = this->head->next;
		temp->next = NULL;
		delete temp;
		--level;
	}

	int getLevel() { return this->level; }

	char** getMap(int find) {
		MapData* it = this->head;
		for (int i = 0; i < this->level; ++i) {
			if (i != find) {
				it = it->next;
			}
			else {
				return it->map;
			}
		}
		return NULL;
	}

	char** getFrontMap() { return head->map; }
	int getFrontID() { return head->id; }
	int getFrontMinTime() { return head->minTime; }
	MapData* getFrontNode() { return head; }

	bool SkipNextStage() {
		if (head->next == NULL || head->next->next == NULL) return true;
		MapData* temp = head->next;
		head->next = temp->next;
		temp->next = NULL;
		queue.push(temp);
		return false; // not win but skip
	}

	void AppendNextStage() {
		if (queue.empty()) return;
		MapData* temp = NULL;
		
		if (head->next == NULL) {
			head->next = queue.front();
			queue.pop();
		}
		else {
			temp = head->next;
			head->next = queue.front();
			queue.pop();
			head->next->next = temp;
			temp = NULL;
		}
	}
};

class MenuDLL {
private:
	struct node {
		char s[100];
		double timer;
		node* prev, * next;
	};

	node* baru, * head = NULL, * tail = NULL, * hapus, * bantu;
	int n = 0;
public:

	void buat_baru() {
		baru = new (node);
		char tmp;
		scanf("%c", &tmp);
		cout << "Username : "; scanf("%[^\n]", baru->s);
		baru->prev = NULL;
		baru->next = NULL;
	}

	void tambah_depan() {
		buat_baru();
		if (head == NULL) {
			head = baru;
			tail = baru;
		}
		else {
			baru->next = head;
			head->prev = baru;
			head = baru;
		}
		++n;
	}

	void savetxt() {
		FILE* f;
		f = fopen("scoreboard.txt", "ab");
		if (f == NULL)
		{
			printf("error");
		}

		while (this->head != NULL) {
			head->timer = elapsedTime;
			fprintf(f, "%s - %f\n", head->s, head->timer);
			head = head->next;
		}

		fclose(f);
	}

	void readtxt() {

		ifstream ifs("scoreboard.txt");

		if (ifs.is_open()) {
			cout << "\nPlayer that already win this game!\n";
			string input; int counter = 1;
			while (getline(ifs, input)) {
				cout << counter++ << ". " << input << " seconds" << endl;
			}
			ifs.close();
			cout << '\n';
		}
		else {
			cout << "No data!\n";
		}

	}

	void tampil(){
		if (head == NULL)
			cout << "Kosong" << endl;
		else
		{
			bantu = head;
			while (bantu != NULL)
			{
				cout << bantu->s << " ";
				bantu = bantu->next;
			}
			cout << endl;
		}
	}
};

MenuDLL ddl;

class State;

class StateData {
public:
	stack<State*>* states; // point to stack of states in game class
};

class State {
protected:
	StateData* stateData;
	stack<State*>* states;
	bool quit, pause;
public:
	State(StateData* state_data) : stateData(state_data), quit(false), pause(false), states(state_data->states) {}
	virtual ~State() {}
	void EndState() { this->quit = true; }
	void Unpause() { this->pause = false; }
	void Pause() { this->pause = true; }
	const bool& Quit() const { return this->quit; }
	virtual void ProcessInput() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

class GameState : public State {
private:

	class Entity {
	public:
		int x, y, old_x, old_y;
		char c;
		Entity(char c = 'E', int x = 1, int y = 1, int olx = 1, int oly = 1) : c(c), x(x), y(y), old_x(olx), old_y(oly) {}
	};

	class Bomb : public Entity {
	public:
		bool explode;
		Bomb(char c, int x, int y, int olx, int oly, bool expl = false) : Entity(c, x, y, olx, oly), explode(expl) {}
	};

	class StagePos {
	public:
		int next_stage_x, next_stage_y;
		char next_stage_c;
	};

	struct Walk {
		int Walk_count;
		int x;
		int y;
		int back;
		Walk(int x, int y, int Walk, int back) : x(x), y(y), Walk_count(Walk), back(back) {}
	};

	struct Target {
		int x;
		int y;
		Target(int x, int y) :x(x), y(y) {}
	};

	Timer screenAnimation, stageTime; // timer for how long player play the game and timer for screen animation
	int mode, speedmod, frame, lives, direction; // movement mode, current level, enemy speed, frame, player total lives, player direction
	bool over, win, animation; // game over, win or not, animation play or not
	deque<Target> Walk_Queue;
	deque<Walk> BFSQueue; 
	MapQueueList list; // list of map
	StagePos pos; // gate to next stage or level
	Entity player, enemy;  // player and enemy
	vector <Bomb*> bomb; // bomb
	char tmp_map[row][col]; // temp map for bfs
	char cmap[row][col]; // actual map

	void AddArray(int x, int y, int wc, int back) {
		// if this path (v) is unexplored and is a path
		if (this->tmp_map[y][x] == ' ') {
			// mark this path (v) as explored
			this->tmp_map[y][x] = '#';
			Walk tmp(x, y, wc, back);
			// Enqueue v to Q
			this->BFSQueue.push_back(tmp);
		}
	}

	void BFS(int sx, int sy, int x, int y) {
		/*
			BFS(Graph G, start vertex s):
				Let Q = an empty Queue
				Mark s as explored, enqueue s to Q
				While Q is not empty:
					u = Q.dequeue
					For each edge (u, v):
						If v is unexplored:
						Mark v as explored
						Enqueue v to Q

		*/
		// make a copy of map, in pseudocode this is (G)
		memcpy(this->tmp_map, this->cmap, sizeof(this->cmap));
		this->BFSQueue.clear();
		Walk walk(sx, sy, 0, -1);
		this->BFSQueue.push_back(walk);
		int depth = 0; 
		while (!this->BFSQueue.empty() && depth < this->BFSQueue.size()) {
			if (this->BFSQueue[depth].x == x && this->BFSQueue[depth].y == y) { 

				this->Walk_Queue.clear(); 
				while (this->BFSQueue[depth].Walk_count != 0) {
					Target target(this->BFSQueue[depth].x, this->BFSQueue[depth].y);
					this->Walk_Queue.push_back(target);
					depth = this->BFSQueue[depth].back;
				}

				break;
			}

			AddArray(this->BFSQueue[depth].x + 1, this->BFSQueue[depth].y, this->BFSQueue[depth].Walk_count + 1, depth);
			AddArray(this->BFSQueue[depth].x - 1, this->BFSQueue[depth].y, this->BFSQueue[depth].Walk_count + 1, depth);
			AddArray(this->BFSQueue[depth].x, this->BFSQueue[depth].y + 1, this->BFSQueue[depth].Walk_count + 1, depth);
			AddArray(this->BFSQueue[depth].x, this->BFSQueue[depth].y - 1, this->BFSQueue[depth].Walk_count + 1, depth);

			++depth;
		}

		this->BFSQueue.clear();
	}

	void LoadMap(char** m) {
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				this->cmap[i][j] = m[i][j];
	}
public:
	void ResetPosition() {
		player.x = 1; player.y = 1; player.c = 'A';
		enemy.x = 60; enemy.y = 18; enemy.c = 'M';
		pos.next_stage_x = 60; pos.next_stage_y = 18; pos.next_stage_c = 'N';
	}

	void Initialize(int speedmod = 3) {
		this->direction = 0;
		this->speedmod = speedmod;
		this->frame = 0;
		this->mode = 1;
		this->over = false;
		this->win = false;
		this->animation = false;
		this->ResetPosition();

		ll.push_back(make_pair(list.getFrontID(), list.getFrontMinTime()));
		LoadMap(this->list.getFrontMap()); // load this map

		while (!this->bomb.empty()) { delete this->bomb.back(); this->bomb.pop_back(); } // clear

		// initiaize
		while (bomb.size() < bomb_count) {
			int bx = rand() % 60 + 1, by = rand() % 17 + 1;
			if (this->cmap[by][bx] == ' ') this->bomb.push_back(new Bomb('B', bx, by, bx, by));
		}

		// clear
		system("CLS");
		ShowMap();
		BFS(this->enemy.x, this->enemy.y, this->player.x, this->player.y);
		this->stageTime.start();
	}

	GameState(StateData* state_data, int stage, int diff) : State(state_data), lives(lvl) {
		this->Initialize(diff);
		timer.start();
	}

	~GameState() { 
		while (!bomb.empty()) { 
			delete this->bomb.back(); 
			this->bomb.pop_back(); 
		}
		BFSQueue.clear();
		Walk_Queue.clear();
	}

	void ShowMap() {
		// print as string
		for (int i = 0; i < row; ++i) {
			printf("%s\n", this->cmap[i]);
		}
	}

	void GameLogic() {

		if (this->over) {
			// play animation
			if (!this->animation) { this->screenAnimation.start(); this->animation = true; }

			// if animation is play more than 5 second, lets end this game state
			if (this->screenAnimation.elapsedSeconds() >= 5) {
				this->screenAnimation.stop();
				if (this->win) {
					cout << "Linked List: ";
					for (int i = 0; i < ll.size(); ++i) {
						cout << ll[i].first << ' ';
					} cout << '\n';
					ddl.tambah_depan();
					ddl.savetxt();
				}
				ll.clear();
				this->EndState();
			}
		}

		// auto reference iterator
		for (auto& it : this->bomb) {
			if (it->x == this->player.x && it->y == this->player.y && it->explode == false) {
				it->explode = true;
				--this->lives;
			}
		}

		// if enemy catch player
		if (this->enemy.x == this->player.x && this->enemy.y == this->player.y) { --this->lives; gotoxy(this->enemy.x, this->enemy.y); cout << ' '; this->ResetPosition(); }

		// if player lives is 0, then game over
		if (this->lives <= 0) {
			this->over = true; this->win = false;
			timer.stop();
		}

		// if player reach gate to next stage
		if (this->player.x == this->pos.next_stage_x && this->player.y == this->pos.next_stage_y) {

			if (list.getFrontNode() != NULL) {
				this->stageTime.stop();

				bool continues = false;

				if (this->stageTime.elapsedSeconds() <= ll.back().second) {
					continues = list.SkipNextStage();
				}
				else {
					list.AppendNextStage();
				}

				list.removeFront(); 
				
				if (continues) { this->over = true; this->win = true; timer.stop(); return; }

				this->Initialize(this->speedmod);
			}
			else {
				this->over = true; this->win = true; timer.stop();
				return;
			}
		}

	}

	void ProcessInput() {
		if (!this->over) {
			if (_kbhit()) {
				switch (_getch()){
				case 's':
					this->direction = 0; // stop
					break;
				case 'm':
					if (this->mode) { // movement mode
						this->mode = 0;
					}
					else {
						this->mode = 1;
					}
					break;
				case 'x':
					this->over = true; // back to menu
					this->EndState();
					break;
				case 'p':
					if (this->pause) { // pause
						this->Unpause();
					}
					else {
						this->Pause();
					}
					break;
				case 'k':
					playlist.PreviousSong();
					break;
				case 'l':
					playlist.NextSong();
					break;
				}
			}
		}
	}

	void Update() {
		this->GameLogic();
		if (!this->over) {
			if (!this->pause) {

				// set last position
				this->player.old_x = this->player.x;
				this->player.old_y = this->player.y;
				this->enemy.old_x = this->enemy.x;
				this->enemy.old_y = this->enemy.y;

				// Clear last position
				gotoxy(this->player.x, this->player.y); cout << " ";
				gotoxy(this->enemy.x, this->enemy.y); cout << " ";

				if (this->mode) {
					if (GetAsyncKeyState(VK_UP)) { if (this->cmap[this->player.y - 1][this->player.x] == ' ')--this->player.y; }
					if (GetAsyncKeyState(VK_DOWN)) { if (this->cmap[this->player.y + 1][this->player.x] == ' ')++this->player.y; }
					if (GetAsyncKeyState(VK_LEFT)) { if (this->cmap[this->player.y][this->player.x - 1] == ' ')--this->player.x; }
					if (GetAsyncKeyState(VK_RIGHT)) { if (this->cmap[this->player.y][this->player.x + 1] == ' ')++this->player.x; }
				}
				else {
					if (GetAsyncKeyState(VK_UP)) { if (this->cmap[this->player.y - 1][this->player.x] == ' ') this->direction = 1; }
					if (GetAsyncKeyState(VK_DOWN)) { if (this->cmap[this->player.y + 1][this->player.x] == ' ') this->direction = 3; }
					if (GetAsyncKeyState(VK_LEFT)) { if (this->cmap[this->player.y][this->player.x - 1] == ' ') this->direction = 4; }
					if (GetAsyncKeyState(VK_RIGHT)) { if (this->cmap[this->player.y][this->player.x + 1] == ' ') this->direction = 2; }

					if (this->direction == 1) { if (this->cmap[this->player.y - 1][this->player.x] == ' ')--this->player.y; }
					if (this->direction == 2) { if (this->cmap[this->player.y][this->player.x + 1] == ' ')++this->player.x; }
					if (this->direction == 3) { if (this->cmap[this->player.y + 1][this->player.x] == ' ')++this->player.y; }
					if (this->direction == 4) { if (this->cmap[this->player.y][this->player.x - 1] == ' ')--this->player.x; }
				}

				// if player old pos and new position is same, do not find path
				if (this->player.old_x != this->player.x || this->player.old_y != this->player.y) {
					BFS(this->enemy.x, this->enemy.y, this->player.x, this->player.y);
				}

				if (this->frame % this->speedmod == 0 && this->Walk_Queue.size() != 0) {
					this->enemy.x = this->Walk_Queue.back().x;
					this->enemy.y = this->Walk_Queue.back().y;
					this->Walk_Queue.pop_back();
					this->frame = 0; // making frame not overflow
				}

				++this->frame;
			}
		}
	}

	void Draw() {
		if (!this->over) {
			if (!this->pause) {
				elapsedTime = timer.elapsedSeconds();
				for (auto& it : this->bomb) {
					if (!it->explode) {
						gotoxy(it->x, it->y); cout << it->c;
					}
				}
				gotoxy(this->player.x, this->player.y); cout << this->player.c;
				gotoxy(this->enemy.x, this->enemy.y); cout << this->enemy.c;
				gotoxy(this->pos.next_stage_x, this->pos.next_stage_y); cout << this->pos.next_stage_c;
				gotoxy(1, 20); cout << "Time: " << elapsedTime;
				gotoxy(1, 21); cout << "Time Stage: " << stageTime.elapsedSeconds();
				gotoxy(1, 22); cout << "HP: " << this->lives;
				gotoxy(1, 23); cout << "ID: " << ll.back().first;
				gotoxy(1, 24); cout << "Min Time: " << ll.back().second;
				gotoxy(1, 26); cout << "                                                                                                             ";
				gotoxy(1, 26); cout << "Song Played: " << playlist.CurrentSong();
				
			}
		}
		else {
			system("CLS"); // clear map and show animation if over
			if (this->win) {
				cout << "+-------------------------------------------------------------------------------------------+\n";
				cout << "|                                                                                           |\n";
				cout << "|                                          You Win!                                         |\n";
				cout << "|                                                                                           |\n";
				cout << "+-------------------------------------------------------------------------------------------+\n";
			}
			else {
				cout << "+-------------------------------------------------------------------------------------------+\n";
				cout << "|                                                                                           |\n";
				cout << "|                                         You Lose!                                         |\n";
				cout << "|                                                                                           |\n";
				cout << "+-------------------------------------------------------------------------------------------+\n";
			}
		}
	}
};

class MainMenuState : public State {
private:
	int chc, stage, difficulty;
public:
	MainMenuState(StateData* state_data) : State(state_data), chc(-1), stage(-1), difficulty(0) {}

	~MainMenuState() {}

	void Update() {
		if (this->chc == 1) {
			this->states->push(new GameState(this->stateData, this->stage, this->difficulty));
		}
		else if (this->chc == 0) {
			this->EndState();
		}
	}

	void Draw() {
		system("CLS");
		cout << "Maze Runner Game:\n";
		cout << " - Total Player lives: " << lvl;
		cout << " - Go to 'E' to next stage, you will win after reach " << lvl + 1 << " stage\n";
		cout << " - Avoid 'M' and 'B'";
		cout << " - Press 'P' to pause/unpause or 'X' to back to main menu\n";

		cout << "\nMenu:\n";
		cout << "1. Play\n";
		cout << "2. Recent Match\n";
		cout << "3. Music Playlist\n";
		cout << "0. Exit\n";
		cout << "Choice: ";
		cin >> this->chc;
	}

	void ProcessInput() {
		if (this->chc == 1) {
			cout << "\nDifficulty:\n";
			cout << "1. Hard (almost impossible)\n";
			cout << "2. Medium\n";
			cout << "3. Easy\n";
			cout << "Choice: ";
			cin >> this->difficulty;
			this->stage = 1;
			if (this->difficulty < 1 || this->difficulty > 3) this->difficulty = 3;
		}
		else if (this->chc == 2) {
			ddl.readtxt();
			system("Pause");
		}
		else if (this->chc == 3) {
			system("CLS");
			playlist.Print();

			cout << "\nMenu: \n";
			cout << "1. Pause / Play\n";
			cout << "2. Previous Song\n";
			cout << "3. Next Song\n";
			cout << "4. Repeat\n";
			cout << "5. Play Random Song\n";
			cout << "6. Play Specific Song\n";
			cout << "7. Shuffle\n";
			cout << "8. Set Volume\n";
			cout << "0. Back\n";
			cout << "Choice: "; int x; cin >> x;

			if (x == 1) { // pause
				if (playlist.isPlay()) playlist.Pause();
				else playlist.Play();
			}
			else if (x == 2) { // prev song
				playlist.PreviousSong();
			}
			else if (x == 3) { // next song
				playlist.NextSong();
			}
			else if (x == 4) { // repeat
				playlist.Repeat();
			}
			else if (x == 5) { // play random song
				playlist.PlayRandom();
			}
			else if (x == 6) { // play specific song based on name
				cout << "\nInput song: "; string songname; cin.ignore(); getline(cin, songname);
				playlist.PlaySpecific(songname);
			}
			else if (x == 7) {
				playlist.Shuffle();
			}
			else if (x == 8) {
				cout << "\nInput volume (0 - 1000): "; int vl; cin >> vl;
				playlist.Volume(vl);
			}
			else { 
				return;
			}
		}
	}
};

class MazeRunnerGame {
private:
	StateData stateData; // statedata
	stack<State*> states; // stack of states
	bool windowOpen; // window open
public:
	MazeRunnerGame() {
		playlist.Play();
		this->windowOpen = true;
		this->stateData.states = &this->states;
		this->states.push(new MainMenuState(&this->stateData)); // push main menu
	}
	virtual ~MazeRunnerGame() {
		while (!this->states.empty()) {
			delete this->states.top();
			this->states.pop();
		}
	}
	void Update() {
		// update the top state of the stack
		if (!this->states.empty()) {
			this->states.top()->Update();
			if (this->states.top()->Quit()) {
				this->states.top()->EndState();
				delete this->states.top();
				this->states.pop();
				playlist.PlayRandom();
			}
		}
		else {
			this->windowOpen = false; // exit loop
		}
	}
	void Draw() {
		// draw the top state
		if (!this->states.empty())
			this->states.top()->Draw();
	}
	void ProcessInput() {
		// process input for top state
		if (!this->states.empty())
			this->states.top()->ProcessInput();
	}
	void Run() {
		// while window is open do update, draw, input processing, with sleep for 0.1 second
		while (this->windowOpen) {
			this->Update();
			this->Draw();
			this->ProcessInput();
			Sleep(100);
		}
	}
};

int main() {
	srand((unsigned)time(NULL));
	MazeRunnerGame game;
	game.Run();
	return 0;
}