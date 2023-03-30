REGISTRY = wyga/deploy-template:v1
BUILDX = docker buildx build --platform linux/amd64,linux/i386,linux/arm/v6,linux/arm/v7,linux/arm64/v8,linux/ppc64le,linux/s390x
OUTPUT = --output type=image,name=$(REGISTRY),push=true,compression=zstd,compression-level=22,force-compression=true,oci-mediatypes=true
OPTIONS = --provenance=false
all:
	$(BUILDX) $(OUTPUT) $(OPTIONS) --pull -f build/Dockerfile build
