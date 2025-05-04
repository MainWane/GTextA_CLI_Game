#!/bin/bash

VM_USER="ulrik2"
VM_IP="192.168.242.130"
REMOTE_DIR="/home/$VM_USER/UAW-Repo-2025"

# Fjern mappen først, hvis du vil sikre en frisk kopi (valgfrit)
# ssh "$VM_USER@$VM_IP" "rm -rf $REMOTE_DIR"

# Brug scp i stedet for rsync
scp -r ./ "$VM_USER@$VM_IP:$REMOTE_DIR"

echo "✅ Projektet er overført til $VM_USER@$VM_IP:$REMOTE_DIR"
