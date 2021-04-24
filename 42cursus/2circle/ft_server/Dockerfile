FROM	debian:buster

ENV AUTOINDEX on

RUN	apt-get update && \
	apt-get upgrade -y && \
	apt-get install -y \
	nginx \
	openssl \
	mariadb-server \
	php7.3-fpm \
	php-mysql \
	php-mbstring \
	wget \
	vim

#RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf

COPY	./srcs/run.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp

EXPOSE	80 443

# ENTRYPOINT ["bash", "run.sh"]
# CMD tail -f /dev/null
CMD bash run.sh
