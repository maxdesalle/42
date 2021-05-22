# ```ft_services```
This project consist to clustering a docker-compose application and deploy it with Kubernetes.

## How to use it
In order to use ft_services, simply execute the following command at the root of the repository:
```bash
./setup.sh
```
Once the above command is executed, the script will start building the Docker containers for each service. When the building process is finished, you can open the dashboard to monitor the services with the following command:
```
minikube dashboard
```

## What I learned
This project was more complicated than I thought. I probably hadn't the right way of doing things from the start. I first started by trying to more or less set up together, without focusing on getting each Docker container to (really) work individually. One more reason to plan things before starting a project.

## Warning
The structure of this repository does **not** necessarily follow the guidelines.
If this is the case, it's to add some clarity in how the files are structured.

## License
Everything in this repository is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).
