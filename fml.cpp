// stop the horriffic bug

// Most of the time it’ll work fine. Including the debugger. Your best bet to find this is Thread Sanitizer. 
// Barring that, run your unit tests in a loop and hope you get lucky with some bad timing in code your 
// didn’t even know had a problem. Barring that, you get rare mystery crashes in production. Fun! 

struct Foo {
  std::jthread thread;
  Bar bar;
  void threadFunc() { bar.doTheThing(); }
  Foo() : thread(&Foo::threadFunc, this) {}
};

int main() {
  Foo foo;
  return 0;
}

