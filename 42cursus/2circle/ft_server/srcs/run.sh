#!/bin/bash

# 권한설정
chmod 775 /run.sh
chown -R www-data:www-data /var/www/
chown -R www-data:www-data /var/nginx/
chmod -R 755 /var/www/

# ssl 개인키 및 인증서 생성
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Cadet/CN=localhost" -keyout key.key -out cert.crt
chmod 600 key.key cert.crt
mv cert.crt etc/ssl/certs/
mv key.key etc/ssl/private/

# nginx 설정
cp -rp /tmp/default /etc/nginx/sites-available/
sed -i "s/autoindex on/autoindex $AUTOINDEX/g" /etc/nginx/sites-available/default

# wordpress 설치 및 설정
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./tmp/wp-config.php /var/www/html/wordpress

# wordpress를 위한 DB 테이블 생성
service mysql start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" \
	| mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'seungnle'@'localhost' IDENTIFIED BY '1234';" \
	| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'seungnle'@'localhost' WITH GRANT OPTION;" \
	| mysql -u root --skip-password

# phpMyAdmin 설치 및 설정
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
rm phpMyAdmin-5.0.2-all-languages.tar.gz
cp -rp /tmp/config.inc.php /var/www/html/phpmyadmin/

#service nginx start
service php7.3-fpm start
service mysql restart
nginx -g "daemon off;"
# while true;
# 	do echo "container is running..";
# 	sleep 600;
# done
bash
