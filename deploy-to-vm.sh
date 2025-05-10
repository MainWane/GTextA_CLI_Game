# Shell Script til at overfører fra host til VM, virker specifik til én VM


#!/bin/bash

VM_USER="ulrik2"
VM_IP="192.168.242.130"
REMOTE_DIR="/home/$VM_USER/UAW-Repo-2025"

# Kode til at rydde op
# ssh "$VM_USER@$VM_IP" "rm -rf $REMOTE_DIR"

# Koden scp til at overføre filerne
# -r: sikrer rekursiv overførsel af mapper
scp -r ./ "$VM_USER@$VM_IP:$REMOTE_DIR"

echo "✅ Projektet er overført til $VM_USER@$VM_IP:$REMOTE_DIR"
