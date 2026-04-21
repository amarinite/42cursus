> [!NOTE]
> Hola amigos

*This project has been created as part of the 42 curriculum by amarquez*

# Inception

## Description
This project's goal is to build a network of interdependant containers using Docker and Docker Compose. For that, one Dockerfile must be defined for each service, as well as the additional files needed, such as shell scripts or config files. 

### Core Services
* **MariaDB:** Relational database management system.
* **WordPress with PHP-FPM:** Content Management System utilizing FastCGI Process Manager.
* **Nginx:** High-performance web server acting as the secure entry point (TLS/SSL).

### Bonus Services
* **Adminer:** Database management tool with a graphical interface.
* **FTP Server:** Secure access to the website's files via vsftpd.
* **Glances:** Real-time system and container monitoring tool.
* **Redis:** Object cache for WordPress to improve loading speeds.
* **Static Site:** A simple, high-performance site serving static content.

---

## Key Concepts

### Differences between Virtual Machines and Docker
A virtual machine virtualizes hardware via a hypervisor, requiring a full guest Operating System for every instance, while a Docker container OS-level virtualization, sharing the host's kernel but isolating the process, which is much lighter than a traditional VM. These containers are highly portable and fast to deploy, since they only package the application and its direct dependencies rather than an entire OS.

### Secrets vs Environment Variables
This projects defines environment variables for non-sensitive data such as user names or web urls, variables that the containers need for their setup. Passwords are defined as secrets, which is a Docker service that makes storing credentials more secure. The main difference is that env variables are visible in the container's metadata via commands like docker inspect. Secrets, however,are not stored in the image or the container’s environment; instead, they are mounted as temporary files into the container at runtime.

### Docker Network vs Host Network
Defining a Docker Network allows different containers to communicate with each other. By default, they run on the host network, which means they share the host’s IP stack and ports directly. To ensure they can only talk to each other, we define a network inside our docker-compose.yml file, which provides a private, isolated virtual network where containers can communicate with each other using their service names as hostnames (DNS resolution).

### Docker Volums vs Bind Mounts
Docker Volumes are paths managed by Docker within a dedicated area of the host's filesystem (usually /var/lib/docker/volumes/). In this project, we use Named Volumes with the local driver. This allows Docker to manage the volume lifecycle while we explicitly point the "device" to a specific path on the host (/home/amarquez/data/). In contrast, bind mounts are not managed by docker and don't show up in `docker volume ls` and similar tools.

---

## Instructions
To build, launch, and test the project, refer to the dedicated documentation files:
* [**USER_DOC.md**](./USER_DOC.md) — For end-users/administrators: setup, access, and service overview.
* [**DEV_DOC.md**](./DEV_DOC.md) — For developers: environment setup, Makefile commands, and data persistence.

---

## Resources
### Core Services
* **MariaDB:** [Alpine-MariaDB reference](https://github.com/yobasystems/alpine-mariadb/)
* **PHP-FPM:** [In-depth Guide](https://atatus.com/blog/what-is-php-fpm-in-depth-guide/) | [Pool Directives 101](https://myjeeva.com/php-fpm-configuration-101.html#pool-directives)
* **WordPress:** [Official Hosting Requirements](https://make.wordpress.org/hosting/handbook/server-environment/)
* **Nginx:** [Practical Beginner's Guide](https://mohammadtaheri.medium.com/practical-nginx-a-beginners-step-by-step-project-guide-6f4c7540c06f) | [Official Documentation](https://nginx.org/en/docs/)
* **Security:** [What is an SSL Certificate?](https://aws.amazon.com/es/what-is/ssl-certificate/)

### Bonus Services
* **Redis:** [Official Docker Implementation](https://redis.io/docs/latest/operate/oss_and_stack/install/install-stack/docker/)
* **Adminer:** [Official Image Repository](https://github.com/TimWolla/docker-adminer/)
* **FTP:** [vsftpd configuration man pages](https://linux.die.net/man/5/vsftpd.conf)

### General Learning
* **Alpine:** [Alpine Docs](https://docs.alpinelinux.org/user-handbook/0.1a/index.html)
* **Docker:** [DevOps with Docker (University of Helsinki)](https://courses.mooc.fi/org/uh-cs/courses/devops-with-docker-spring-2026/)
* **Community:** jgirbau's Cloudflare WARP hack and the "Explain Like I'm Five" communities.

---

## AI Usage
AI was used in this project as a guided learning tool. It has provided me a roadmap to begin my research on many topics related to the subject, such as understanding what PHP-FPM actually is and why WordPress needs it, why TLS means we require a self-signed certificate or how Nginx communicates with PHP-FPM. It has also been used to debug some issues, mostly related to mismatched config files, and to correct spelling mistakes from the md files.