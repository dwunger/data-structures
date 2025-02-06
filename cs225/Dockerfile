FROM james9909/cs225-autograder:latest
RUN yum install -y gdb
RUN yum install -y vim
RUN echo "alias cls='clear'"  >> ~/.bashrc
RUN echo "alias clip='xclip -selection clipboard'"  >> ~/.bashrc
ENTRYPOINT bash
