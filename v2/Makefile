REGISTRY = wyga/deploy-template:v2
PLATFORM = linux/amd64,linux/arm64/v8
BUILDX = docker buildx build --platform $(PLATFORM)
OUTPUT = --output type=image,name=$(REGISTRY),push=true,compression=zstd,compression-level=22,force-compression=true,oci-mediatypes=true
OPTIONS = --provenance false
all:
	$(BUILDX) $(OUTPUT) $(OPTIONS) --pull -f build/Dockerfile .
