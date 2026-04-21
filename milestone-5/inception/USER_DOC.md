# USER_DOC.md — User Documentation

## Project description

This project launches a series of containerized services built from scratch using Alpine Linux as a base. These services are:
* **WordPress:** A container with `php-fpm` configured to serve the CMS.
* **MariaDB:** A database container for storing the website's data.
* **Nginx:** A web server acting as the entry point for the application.
* **Bonus Services:**
	* **FTP:** A container allowing remote access to the website's files.
	* **Adminer:** A web-based GUI for managing the MariaDB database.
	* **Redis:** A caching service to improve WordPress performance.
	* **Static Site:** A separate web container serving a simple static site.
	* **Glances:** A real-time system monitoring tool providing an overview of all services.

---

## Setting up the project
For security reasons, all credentials are stored as Docker secrets and environment variables. They must be defined before launching the project.

* **Passwords:** Credentials must be defined in the `secrets/` directory at the project root.
* **Database User:** Defined as `MYSQL_USER` in the `.env` file.
* **WordPress Admin:** Defined as `WP_ADMIN_USER` in the `.env` file.
* **WordPress User:** Defined as `WP_USER` in the `.env` file.
* **FTP User:** Defined as `FTP_USER` in the `.env` file.

> **Note:** To change a password, you must update the corresponding `.txt` file in the `secrets/` folder and restart using `make re`.

---

## Accessing the Services

To access the WordPress website and other services using the required domain name, you must configure your local machine to recognize `amarquez.42.fr` (or your own domain).

### 1. Configure the Hosts File
Since the services are running locally, you need to map the domain name to your local IP address (or `127.0.0.1`).

1. Open a terminal on your host machine.
2. Edit the `/etc/hosts` file with root privileges:
	```bash
	sudo nano /etc/hosts
	```
3. Add the following line to the end of the file:
	```text
	127.0.0.1  amarquez.42.fr
	```

### 2. Access the service URLs
* **WordPress Website:** [https://amarquez.42.fr](https://amarquez.42.fr)
* **Adminer (Database Management):** [http://amarquez.42.fr:8080](http://amarquez.42.fr:8080)
* **Glances (System Monitoring):** [http://amarquez.42.fr:61208](http://amarquez.42.fr:61208)
* **Static Site:** [http://amarquez.42.fr:80](http://amarquez.42.fr:80)
* **FTP Server:** Access via Filezillaor similar clients on port 21.
* **Redis:** Check `docker exec -it redis redis-cli monitor`.