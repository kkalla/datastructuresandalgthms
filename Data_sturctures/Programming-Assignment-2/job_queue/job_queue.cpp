#include <iostream>
#include <vector>
#include <algorithm>


using std::vector;
using std::cin;
using std::cout;

class Thread {
	private:
		int index;
		int duration;
	public:
		Thread() {}
		Thread(int x,int y):index(x),duration(y){}
		~Thread() {}
		int getIndex() {return index;}
		int getDuration() {return duration;}
		void setIndex(int);
		void setDuration(int);
};
void Thread::setIndex(int x){
	index=x;
}
void Thread::setDuration(int y){
	duration=y;

}



class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<int> unassigned_workers_;
  vector<long long> start_times_;
  vector<Thread> threads_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }



void SiftDown(int i){
	int minIndex = i;
	int l = 2*i+1;
	int size = threads_.size();
	if(l<=size && threads_[l].getDuration()<threads_[minIndex].getDuration())
		minIndex = l;
	int r = 2*i + 2;
	if(r<=size && threads_[r].getDuration()<threads_[minIndex].getDuration())
		minIndex = r;
	if(i!=minIndex){
		std::swap(threads_[i],threads_[minIndex]);
		return SiftDown(minIndex);
	}
}


void BuildHeap(vector<Thread> threads){
	int size = threads.size();
	for(int i=size/2;i>0;i--)
		SiftDown(i);
}

void SiftUp(int size){
	while(size>0 && 
	threads_[(size-1)/2].getDuration()<threads_[size].getDuration()){
		std::swap(threads_[(size-1)/2],threads_[size]);
		size = (size-1)/2;
	}
}

Thread ExtractMin(){
	int threads_size = threads_.size();
	Thread result = threads_[0];
	threads_[0] = threads_[threads_size];
	threads_size -= 1;
	threads_.resize(threads_size);
	SiftDown(0);
	return result;
}

int GetMin(){
	Thread result_Thread = threads_[0];
	int result = result_Thread.getDuration();
	return result;
}

void Insert(Thread thread){
	threads_.push_back(thread);
	int size = threads_.size();
	SiftUp(size);
}




  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }


  void AssignJobs() {
	  start_times_.resize(jobs_.size());
	  threads_.resize(num_workers_);
	  int remain_jobs = jobs_.size();
	  int threads_size = threads_.size();
	  long long time = 0;
	  int curr_state;
	  for(int i=0;i<num_workers_;++i){
		  threads_[i].setIndex(i);
		  threads_[i].setDuration(jobs_[i]);
		  start_times_[i]=time;
		  assigned_workers_.push_back(i);
	  }
	  remain_jobs -=num_workers_;
	  BuildHeap(threads_);
	  while(remain_jobs){
		  curr_state = jobs_.size()-remain_jobs-1;
		  time += GetMin();
		  int minDur = GetMin();
		  unassigned_workers_.clear();
		  for(int i=0;GetMin()!=minDur;++i){
			  Thread minThread = ExtractMin();
			  unassigned_workers_.push_back(minThread.getIndex());
		  }
		  sort(unassigned_workers_.begin(),unassigned_workers_.end());
		  for(int i=0;i<unassigned_workers_.size();++i){
			  Thread newThread;
			  newThread.setIndex(unassigned_workers_[i]);
			  newThread.setDuration(jobs_[curr_state + i]);
			  assigned_workers_.push_back(newThread.getIndex());
			  start_times_.push_back(time);
			  Insert(newThread);
		  }
		  remain_jobs -= unassigned_workers_.size();
	  }






			  




    // TODO: replace this code with a faster algorithm.
    /*assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }*/

  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    //WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
