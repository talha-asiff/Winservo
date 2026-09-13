// --- Interactive Star Button Logic ---
function handleStarClick() {
    const starBtn = document.getElementById('star-btn');
    const starIcon = document.getElementById('star-icon');
    const starText = document.getElementById('star-text');
    const toast = document.getElementById('toast');

    // Toggle Starred visual state
    starBtn.classList.add('starred');
    starIcon.classList.remove('fa-regular');
    starIcon.classList.add('fa-solid');
    starText.textContent = "Starred on GitHub!";

    // Show feedback toast
    toast.classList.add('show');

    // Redirect after brief visual feedback
    setTimeout(() => {
        window.open('https://github.com/talha-asiff', '_blank');
        toast.classList.remove('show');
    }, 1200);
}

// --- Canvas Network Particle Background ---
const canvas = document.getElementById('bg-canvas');
const ctx = canvas.getContext('2d');

let width, height;
let particles = [];

function resizeCanvas() {
    width = canvas.width = window.innerWidth;
    height = canvas.height = window.innerHeight;
}

class Particle {
    constructor() {
        this.x = Math.random() * width;
        this.y = Math.random() * height;
        this.vx = (Math.random() - 0.5) * 0.8;
        this.vy = (Math.random() - 0.5) * 0.8;
        this.radius = Math.random() * 1.5 + 1;
    }

    update() {
        this.x += this.vx;
        this.y += this.vy;

        if (this.x < 0 || this.x > width) this.vx *= -1;
        if (this.y < 0 || this.y > height) this.vy *= -1;
    }

    draw() {
        ctx.beginPath();
        ctx.arc(this.x, this.y, this.radius, 0, Math.PI * 2);
        ctx.fillStyle = 'rgba(64, 196, 255, 0.5)';
        ctx.fill();
    }
}

function initParticles() {
    particles = [];
    const count = Math.min(Math.floor(width * 0.05), 65);
    for (let i = 0; i < count; i++) {
        particles.push(new Particle());
    }
}

function connectParticles() {
    for (let i = 0; i < particles.length; i++) {
        for (let j = i + 1; j < particles.length; j++) {
            const dx = particles[i].x - particles[j].x;
            const dy = particles[i].y - particles[j].y;
            const dist = Math.sqrt(dx * dx + dy * dy);

            if (dist < 130) {
                ctx.beginPath();
                ctx.moveTo(particles[i].x, particles[i].y);
                ctx.lineTo(particles[j].x, particles[j].y);
                ctx.strokeStyle = `rgba(64, 196, 255, ${0.15 * (1 - dist / 130)})`;
                ctx.lineWidth = 1;
                ctx.stroke();
            }
        }
    }
}

function animate() {
    ctx.clearRect(0, 0, width, height);
    particles.forEach(p => {
        p.update();
        p.draw();
    });
    connectParticles();
    requestAnimationFrame(animate);
}

window.addEventListener('resize', () => {
    resizeCanvas();
    initParticles();
});

// Initialize on page load
resizeCanvas();
initParticles();
animate();