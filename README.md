# Control Car mode desired from application whether automatic or manually 


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

#### install node modules for react app and start the app

navigate to react directory:
```bash
cd react/
npm install
npm start
```

#### Start the server in another terminal by navigating to App directory then run:

```bash
cd App/
python web_cam.py
```


Now your application is ready to detect the direction of the driving-car.