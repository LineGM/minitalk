<h1 align="center">
  minitalk
</h1>

<p align="center">
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/LineGM/minitalk?color=critical"/>
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/LineGM/minitalk?color=yellow"/>
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/LineGM/minitalk?color=blue"/>
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/LineGM/minitalk?color=green"/>
</p>

---

## About the project

> _The purpose of this project is to code a small data exchange program using
UNIX signals._

For more detailed information: [**subject**](https://github.com/LineGM/minitalk/blob/main/minitalk_en.pdf).

## Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling**

To compile, go to the project path and run:

```shell
$ make
```

**2. Testing**

To test the program you just need to launch the "server" and the "client" in different shell tabs with the following:

```shell
$ ./server
```

This will show your PID to make the client work and will stay waiting to receive a message from the "client"

```shell
$ ./client "PID" "Your message string"
```

By launching it, this will show "Your message string" on the server window.
