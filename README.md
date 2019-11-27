# Introduction
These code reimplement in C++ the algorithm described in the paper _A Functional Description of TeX's Formula Layout_. The original SML implementation can be found at [ftp://ftp.cs.uni-sb.de/formulae](ftp://ftp.cs.uni-sb.de/formulae).


With the SML implementation at hand, our rewriting is quite straightforward. As in the SML implementation, we leave out the parts of `Accent.h` and `Radical.h`. But we add some experimental code to `Delimiter.h`. It will not be hard to complete the missing parts, though perhaps laborious.


## Run the code
Make sure that the working directory is `fonts` when running the executable.


```bash
$ cd formulae-cxx
$ mkdir build
$ cd build
$ cmake ..
$ make
$ cd ../fonts
$ ../build/formulae
```

Find `this.dvi` in the `fonts` directory. To view `.dvi` files, we may use dvi-viewers like `xdvi`, or convert them to `.pdf` files via `dvipdf`.
