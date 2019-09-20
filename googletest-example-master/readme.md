# Example project on how to use Google tests #

This is a very simple project. It defines two libraries that are interconnected
and tests them. The names could have definitely been better, but are good enough
to illustrate the purpose.

# How to build #

Clone this repository to folder `<folder>`. Then:
```bash
cd <folder>/clever_name
mkdir build
cd build
cmake ..
make
ctest -VV
```


# Contribute #

See something that can be improved or have a question? Open an issue in this
repository.
