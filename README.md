# Detecting lane lines using openCV
# Control Car mode desired from application


### Installing Dependencies

> I assume you're using linux, using windows should work fine but with some few tweaks.

#### Python 3.7+

Follow instructions to install the latest version of python for your platform in the [python docs](https://docs.python.org/3/using/unix.html#getting-and-installing-the-latest-version-of-python)

#### Virtual Enviornment

It is recommended working within a virtual environment whenever using Python for projects. This keeps your dependencies for each project separate and organaized. Instructions for setting up a virtual enviornment for your platform can be found in the [python docs](https://packaging.python.org/guides/installing-using-pip-and-virtual-environments/)

#### PIP Dependencies

Once you have your virtual environment setup and running, install dependencies by running:

```bash
pip install -r requirements.txt
```

This will install all of the required packages selected within the `requirements.txt` file.

## Implementing the project


First, clone the pybind11 repository by running:

```bash
git clone https://github.com/pybind/pybind11.git
```

Compile c++ code by running:
> You need to install cmake and make
```bash
mkdir build
cd build/
cmake ..
make
```

Navigate back to the project directory by running: 
```bash
cd ../ 
```

### Runnig the program
```bash 
python run.py 
```

## Expected Ouput
![Output Plot](Output.png)
From the output plot, we can see that FT time complexity is in the order of N^2 while FFT is in the order of (N log(N)).
The output error is almost zero.
