//shared_ptr: keep count hwo many references to same object
//last pointer responsible for deleting object

shared_ptr
std::shared_ptr<Song> song_ptr1;
auto song_ptr2=std::make_shared<Song>(): //need make for makeshared, allocate weak ptr
std::cout<<song_ptr2->getTitle()<<endl;
song_ptr2.reset() //reset will take care of deleting dynamic object

  weak_ptr
  std::shared_ptr<Song> another_shared=weaksong.lock();
  if(weak_song.expired()) //returns true if object no longer exists
    
   unique_ptr
   auto song_ptr=std::make_unique<Song>():
   std::unique_ptr<Song> another_song;
   another_song=std::move(songPtr);
