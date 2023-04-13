REGISTRY = wyga/deploy-template:v1
BUILDX = docker buildx build --platform linux/amd64,linux/i386,linux/arm/v6,linux/arm/v7,linux/arm64/v8,linux/ppc64le,linux/s390x
# Someday ...
#OUTPUT = --output type=image,name=$(REGISTRY),push=true,compression=zstd,compression-level=22,force-compression=true,oci-mediatypes=true
OUTPUT = --output type=image,name=$(REGISTRY),push=true,compression=gzip,compression-level=9,force-compression=true,oci-mediatypes=true
OPTIONS = --provenance=false
all:
	$(BUILDX) $(OUTPUT) $(OPTIONS) --pull --no-cache -f build/Dockerfile build
