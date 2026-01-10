# Jenkins CI/CD Pipeline Setup

This document provides instructions for setting up the Jenkins CI/CD pipeline for the Flask Key-Value Store application.

## Prerequisites

- Jenkins server installed and running
- Docker installed on Jenkins server
- Docker Compose installed on Jenkins server
- Git plugin installed in Jenkins
- Docker Pipeline plugin installed in Jenkins

## Jenkins Plugins Required

Install the following plugins in Jenkins:

1. **Git Plugin** - For source code management
2. **Docker Pipeline** - For Docker operations
3. **Pipeline** - For pipeline functionality
4. **Docker Plugin** - For Docker integration
5. **Credentials Binding Plugin** - For secure credential management

## Pipeline Overview

The Jenkins pipeline consists of the following stages:

### 1. **Checkout**
- Pulls the latest code from the Git repository

### 2. **Validate**
- Validates project structure
- Checks for required files (Dockerfiles, docker-compose.yml)

### 3. **Build Backend**
- Builds the Flask backend Docker image
- Tags the image with build number and latest

### 4. **Build Frontend**
- Builds the Nginx frontend Docker image
- Tags the image with build number and latest

### 5. **Test Backend**
- Starts a test container
- Runs health checks and API tests
- Tests all CRUD endpoints
- Cleans up test containers

### 6. **Test Frontend**
- Starts a test container
- Verifies frontend accessibility
- Cleans up test containers

### 7. **Push to Registry** (Main branch only)
- Pushes Docker images to Docker Hub or private registry
- Tags with build number and latest

### 8. **Deploy to Staging** (Develop branch)
- Deploys to staging environment automatically
- Verifies deployment health

### 9. **Deploy to Production** (Main branch)
- Requires manual approval
- Deploys to production environment
- Verifies deployment health

## Setup Instructions

### Step 1: Configure Jenkins Credentials

1. Go to **Jenkins → Manage Jenkins → Manage Credentials**
2. Add the following credentials:

#### Docker Hub Credentials (if pushing to Docker Hub)
- **Kind:** Username with password
- **ID:** `docker-hub-credentials`
- **Username:** Your Docker Hub username
- **Password:** Your Docker Hub password/token

### Step 2: Create Jenkins Pipeline Job

1. Go to **Jenkins → New Item**
2. Enter job name: `flask-kvstore-pipeline`
3. Select **Pipeline** and click OK
4. Configure the pipeline:

#### General Settings
- **Description:** CI/CD pipeline for Flask Key-Value Store
- **Discard old builds:** Keep last 10 builds

#### Build Triggers (Optional)
- ☑ **Poll SCM:** `H/5 * * * *` (Check every 5 minutes)
- ☑ **GitHub hook trigger for GITScm polling** (if using GitHub)

#### Pipeline Configuration
- **Definition:** Pipeline script from SCM
- **SCM:** Git
- **Repository URL:** Your Git repository URL
- **Credentials:** Your Git credentials (if private repo)
- **Branch Specifier:** `*/main` or `*/develop`
- **Script Path:** `Jenkinsfile`

### Step 3: Configure Environment Variables

In the Jenkinsfile, update the following variables if needed:

```groovy
environment {
    DOCKER_REGISTRY = 'docker.io'              // Change if using private registry
    DOCKER_CREDENTIALS_ID = 'docker-hub-credentials'
    BACKEND_IMAGE = 'flask-kvstore-backend'
    FRONTEND_IMAGE = 'flask-kvstore-frontend'
    IMAGE_TAG = "${BUILD_NUMBER}"
    COMPOSE_PROJECT_NAME = 'flask-kvstore'
}
```

### Step 4: Set Up Multi-Branch Pipeline (Optional)

For automatic branch detection:

1. Go to **Jenkins → New Item**
2. Enter name: `flask-kvstore-multibranch`
3. Select **Multibranch Pipeline**
4. Configure:
   - **Branch Sources:** Add Git source
   - **Repository URL:** Your Git repository
   - **Discover branches:** All branches
   - **Build Configuration:** by Jenkinsfile

## Branch Strategy

The pipeline is configured for the following branch strategy:

- **main branch:**
  - Builds and tests
  - Pushes to Docker registry
  - Deploys to production (with manual approval)

- **develop branch:**
  - Builds and tests
  - Deploys to staging automatically

- **feature branches:**
  - Builds and tests only

## Running the Pipeline

### Automatic Trigger
The pipeline will automatically trigger when:
- Code is pushed to the repository
- A pull request is created/updated
- SCM polling detects changes

### Manual Trigger
1. Go to your pipeline job in Jenkins
2. Click **Build Now**
3. Select branch (if using multibranch pipeline)

## Monitoring the Pipeline

### View Pipeline Progress
1. Go to your pipeline job
2. Click on the build number
3. View **Pipeline Steps** or **Console Output**

### View Logs
```bash
# From Console Output in Jenkins UI
# Or via Jenkins CLI
java -jar jenkins-cli.jar -s http://your-jenkins-url/ console <job-name> <build-number>
```

## Deployment Ports

The application uses the following ports:

- **Backend:** 5000 (Flask API)
- **Frontend:** 8080 (Nginx)
- **Backend Test:** 5001 (Temporary during tests)
- **Frontend Test:** 8081 (Temporary during tests)

Ensure these ports are available on your Jenkins server.

## Troubleshooting

### Docker Permission Issues
If Jenkins user doesn't have Docker permissions:
```bash
sudo usermod -aG docker jenkins
sudo systemctl restart jenkins
```

### Port Conflicts
If ports are already in use:
```bash
# Check what's using the port
lsof -i :5000
lsof -i :8080

# Kill the process or change ports in docker-compose.yml
```

### Build Failures
1. Check **Console Output** for error messages
2. Verify all required plugins are installed
3. Ensure Docker is running on Jenkins server
4. Check credentials are properly configured

### Cleanup After Failed Builds
```bash
# Remove dangling containers
docker container prune -f

# Remove unused images
docker image prune -a -f

# Full cleanup
docker system prune -a -f
```

## Security Best Practices

1. **Never commit credentials** to the repository
2. Use Jenkins **Credentials** for sensitive data
3. Enable **RBAC** in Jenkins for access control
4. Use **HTTPS** for Jenkins access
5. Keep Jenkins and plugins **up to date**
6. Use **Docker secrets** for production deployments

## Advanced Configuration

### Using Private Docker Registry

Update Jenkinsfile environment:
```groovy
environment {
    DOCKER_REGISTRY = 'registry.example.com'
    DOCKER_CREDENTIALS_ID = 'private-registry-credentials'
}
```

### Adding Slack Notifications

Install **Slack Notification Plugin** and add to Jenkinsfile:
```groovy
post {
    success {
        slackSend(color: 'good', message: "Build Successful: ${env.JOB_NAME} ${env.BUILD_NUMBER}")
    }
    failure {
        slackSend(color: 'danger', message: "Build Failed: ${env.JOB_NAME} ${env.BUILD_NUMBER}")
    }
}
```

### Email Notifications

Add to Jenkinsfile:
```groovy
post {
    always {
        emailext(
            subject: "Pipeline ${currentBuild.result}: ${env.JOB_NAME}",
            body: "Build ${env.BUILD_NUMBER} - ${currentBuild.result}",
            to: 'team@example.com'
        )
    }
}
```

## Next Steps

1. Set up staging and production environments
2. Configure monitoring and alerting
3. Implement automated rollback mechanisms
4. Add integration tests
5. Set up backup and disaster recovery
