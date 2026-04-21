# DEV_DOC.md — Developer Documentation

## 1. Environment Setup

### Prerequisites
* **Operating System:** Linux (or a VM running Linux).
* **Docker & Docker Compose:** Must be installed and configured on the host machine.
* **Network:** Ports **443**, **80**, **21**, **8080**, and **61208** should be available.
* **Optional:** FileZilla or a similar FTP client for testing the FTP bonus service.

### Configuration Files & Secrets
Before building, you must set up the following files:

#### Secrets
Secrets are required for this project and are located under the secrets/ directory at root. The files that need to be defined are:
* `ftp_password.txt`
* `mysql_password.txt`
* `mysql_root_password.txt`
* `wp_admin_password.txt`
* `wp_user_password.txt`

#### Environment Variables
Environment variables need to be declared at .env file under the srcs/ directory. The required values that need to be defined are:
```env
# Database Config
MYSQL_DATABASE=
MYSQL_USER=
MYSQL_HOST=
MYSQL_CHARSET=utf8mb4
MYSQL_COLLATION=utf8mb4_unicode_ci

# WordPress Config
WP_URL=
WP_TITLE=
WP_ADMIN_USER=
WP_ADMIN_EMAIL=
WP_USER_NAME=
WP_USER_EMAIL=

# FTP Config
FTP_USER=
```
---

## 2. Build and Launch
The project is managed via a **Makefile** located at the root of the repository. This Makefile acts as a wrapper for `docker-compose` to ensure consistent environment handling and volume management.

### Makefile Command Reference
| Command | Action |
| :--- | :--- |
| `make` | **Default:** Creates data directories, builds images, and starts containers in detached mode. |
| `make up` | Starts the containers (useful if they were previously stopped). |
| `make down` | Stops the containers but **preserves** the data volumes. |
| `make clean` | Stops containers and removes the data volumes. |
| `make fclean` | Stops containers, removes all images/networks, and deletes all persistent data from the host. |
| `make re` | Equivalent to `make fclean` followed by `make`. |
| `make downup` | Equivalent to `make down` followed by `make up`. |

---

## 3. Container & Volume Management
Once the stack is running, you can use the following commands to monitor the environment and debug services:
* **Check Status:** `docker ps`  
* **Inspect Logs:** `docker logs <container_name>`  
* **Interactive Shell:** `docker exec -it <container_name> sh`  
* **Volume Management:** 
	* `docker volume ls`
	* `docker volume inspect <volume_name>`

---

## 4. Data Storage and Persistence
This project uses two persistent data storages: one for the wordpress files and one for the database. They are located under the /home/amarquez/data/ directory and they are mounted as named volumes via docker compose.

> **Note:** If running this on a different environment, ajust the base directory `/home/amarquez/data/` to your specific user path and modify the `docker-compose.yml` file.